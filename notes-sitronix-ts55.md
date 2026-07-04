# Sitronix I²C Touchscreen – Driver Research & Design Notes

> **Platform:** Allwinner R528 (ARMv7-A, soft-float/hard-float)
> **Kernel target:** Linux 6.18 (out-of-tree module)
> **I²C address:** 0x55
> **DTS compatible:** `"sitronixts"`
> **Status:** Driver skeleton bootstrapped → full implementation committed

---

## 1. Problem statement

The mainline `st1232_ts` driver (`drivers/input/touchscreen/st1232.c`,
module `st1232`) does not fully support the Sitronix touchscreen IC in this
platform. The stock DTS uses:

```dts
sitronix55: touchscreen@55 {
    compatible = "sitronixts";
    reg = <0x55>;
    interrupt-parent = <&pio>;
    interrupts = <4 1 8>;      /* PB4, falling/active-low */
    irq-gpio = <&pio 4 1 0>;  /* PB4 */
    rst-gpio = <&pio 4 0 0>;  /* PB0 */
    status = "okay";
};
```

This indicates a **non-mainline vendor driver** is expected.  The stock kernel
exports these symbols:

- `sitronix_ts_i2c` (I²C driver name)
- `sitronix_ts.description = Sitronix Touchscreen Controller Driver`
- `sitronix_ts_i2c_init` / `sitronix_ts_i2c_exit` (module init/exit)

---

## 2. Candidate drivers

### 2a. Primary: `sitronix_i2c_touch` (Sitronix vendor driver)

This is the closest match to what the stock image used.  Available as
`sitronix_i2c_touch.c` + `sitronix_i2c_touch.h` from CriticalLink and
various Android/vendor kernel trees.

Key facts:
- Written by Sitronix (GPL-2.0): Rudy Huang / Petitk Kao.
- Targets I²C ICs at 0x55: ST1232, ST1633, ST1663i family.
- Has conditional Sunxi platform hooks (`//#define CONFIG_ARCH_SUNXI`).
- Reads chip ID, resolution, FW revision, protocol type, max touches from
  IC registers rather than DTS — essential for self-describing panels.
- Supports both **A-type** (5 bytes/touch, up to 10 fingers) and
  **B-type** (3 bytes/touch, max 2 fingers) report packets.
- Sensor key support (BACK/HOME/MENU from `KEYS_REG`).
- Optional: monitor thread (Raw CRC watchdog), FW upgrade char device,
  sysfs/proc interface — all compiled-out in this port.

Reference source: https://support.criticallink.com/redmine/attachments/download/15812/sitronix_i2c_touch.c

### 2b. Secondary: mainline `st1232_ts`

Available in `drivers/input/touchscreen/st1232.c`.  Supports
`sitronix,st1232` and `sitronix,st1633` DT compatible strings.
Minimal feature set — does not implement vendor-specific protocol quirks,
sensor keys, or self-description from registers.  Use as last resort only.

---

## 3. Register map (from vendor driver)

| Offset | Name                | Notes                              |
|--------|---------------------|------------------------------------|
| 0x00   | FIRMWARE_VERSION    |                                    |
| 0x01   | STATUS_REG          | [7:4] err_code, [3:0] dev_status   |
| 0x02   | DEVICE_CONTROL_REG  | bit1 = power-down                  |
| 0x04   | XY_RESOLUTION_HIGH  | [7:4]=X_H, [3:0]=Y_H              |
| 0x05   | X_RESOLUTION_LOW    |                                    |
| 0x06   | Y_RESOLUTION_LOW    |                                    |
| 0x0C–0x0F | FIRMWARE_REVISION_3..0 |                               |
| 0x10   | FINGERS             | [3:0] = active touch count         |
| 0x11   | KEYS_REG            | bits 0-2 = BACK/HOME/MENU          |
| 0x12   | XY0_COORD_H         | first touch high nibbles           |
| 0x3E   | I2C_PROTOCOL        | [1:0] = protocol type              |
| 0x3F   | MAX_NUM_TOUCHES     |                                    |
| 0xF4   | CHIP_ID             | [0]=chip_id, [1]=Num_X, [2]=Num_Y |

---

## 4. Protocol types

| Type | Value | Bytes/touch | Max touches | Notes              |
|------|-------|-------------|-------------|--------------------|
| A    | 1     | 5           | max_touches | Standard           |
| B    | 2     | 3           | 2           | Older/simpler ICs  |
| RSVD | 0     | –           | –           | → force B if FW≈0  |

---

## 5. Linux 6.18 adaptation notes

| Vendor driver feature       | 6.18 adaptation                              |
|-----------------------------|----------------------------------------------|
| `CONFIG_HAS_EARLYSUSPEND`   | Removed; use `dev_pm_ops` `.suspend/.resume` |
| `gpio_request` legacy API   | Kept (still valid in 6.18); gpiod preferred  |
| `input_mt_sync()` legacy    | Replaced with `input_mt_init_slots` + slots  |
| `LINUX_VERSION_CODE` guards | Removed; target is 6.18 only                 |
| Monitor thread              | Compiled out (optional, add later)           |
| FW upgrade char device      | Compiled out (optional, add later)           |
| `VERIFY_WRITE` in ioctl     | Removed (dropped in 5.0)                     |
| `access_ok` 2-arg           | Not needed (ioctl removed)                   |

---

## 6. DTS ↔ driver mapping

| DTS property              | Driver field          | Notes                        |
|---------------------------|-----------------------|------------------------------|
| `reg = <0x55>`            | `client->addr`        | Sitronix default address     |
| `compatible = "sitronixts"` | `of_match_table`    | Exact string match           |
| `irq-gpio = <&pio 4 1 0>` | `ts->irq_gpio`        | PB4, read via `of_get_named_gpio_flags` |
| `rst-gpio = <&pio 4 0 0>` | `ts->rst_gpio`        | PB0, output, active-low reset |
| `interrupts = <4 1 8>`    | `client->irq`         | Falling edge, IRQF_TRIGGER_FALLING |

---

## 7. Build instructions

See [`README.md`](README.md) for full build and load instructions.

Quick cross-compile for R528:

```bash
make ARCH=arm \
     CROSS_COMPILE=arm-linux-gnueabihf- \
     KDIR=/path/to/linux-6.18
insmod drivers/input/touchscreen/sitronix_ts_i2c.ko
```

---

## 8. Validation checklist

After `insmod`, check `dmesg` for:

```
sitronix_ts_i2c 1-0055: resolution: NNN x NNN
sitronix_ts_i2c 1-0055: chip_id=N Num_X=N Num_Y=N
sitronix_ts_i2c 1-0055: fw_revision: XX XX XX XX
sitronix_ts_i2c 1-0055: protocol_type=N
sitronix_ts_i2c 1-0055: max_touches=N
sitronix_ts_i2c 1-0055: Sitronix touchscreen probed ...
```

If you see `IC init failed` or I²C errors, check:
1. `twi2` bus is enabled in DTS (`status = "okay"`).
2. No competing driver (e.g. `st1232_ts`) is loaded.
3. Power rails to the touch IC are up before probe.

---

## 9. References

- Sitronix vendor driver: https://support.criticallink.com/redmine/attachments/download/15812/sitronix_i2c_touch.c
- Sitronix vendor header: https://support.criticallink.com/redmine/attachments/download/15811/sitronix_i2c_touch.h
- Mainline st1232 DT binding: `Documentation/devicetree/bindings/input/touchscreen/sitronix-st1232.txt`
- Linux 6.18 input MT API: `include/linux/input/mt.h`
- aic8800d80 driver structure reference: https://github.com/shenmintao/aic8800d80
