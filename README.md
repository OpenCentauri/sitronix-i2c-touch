# sitronix-i2c-touch

Out-of-tree Linux kernel driver for Sitronix I²C touchscreen controllers,
targeting **Linux 6.18** on **Allwinner R528** (and compatible ARMv7-A platforms).

See [`notes-sitronix-ts55.md`](notes-sitronix-ts55.md) for full design rationale,
DTS analysis, and driver selection notes.

---

## Files

```
.
├── Makefile                                  # out-of-tree Kbuild
├── README.md                                 # this file
├── notes-sitronix-ts55.md                    # design/research notes
└── drivers/
    └── input/
        └── touchscreen/
            ├── Kconfig                       # Kconfig fragment
            ├── sitronix_ts_i2c.h             # register map, structs
            └── sitronix_ts_i2c.c             # driver implementation
```

---

## DTS node (your existing stock DTS)

```dts
&twi2 {                          /* I2C bus at 0x2502800 on R528 */
    status = "okay";

    sitronix55: touchscreen@55 {
        compatible = "sitronixts";
        reg = <0x55>;

        interrupt-parent = <&pio>;
        interrupts = <4 1 8>;    /* PB4, falling/active-low */

        irq-gpio = <&pio 4 1 0>; /* PB4 */
        rst-gpio = <&pio 4 0 0>; /* PB0 */

        status = "okay";
    };
};
```

The driver binds to `compatible = "sitronixts"`.  It also accepts
`"sitronix,st1232"` and `"sitronix,st1633"` if you want to align with
mainline DT bindings later.

---

## Building

### Prerequisites

- Linux 6.18 kernel source tree (configured and `modules_prepare` run)
- For R528: `arm-linux-gnueabihf-` cross-compiler (hard-float)

### Native (host kernel)

```bash
make
```

### Cross-compile for Allwinner R528 (ARM32 hard-float)

```bash
make ARCH=arm \
     CROSS_COMPILE=arm-linux-gnueabihf- \
     KDIR=/path/to/linux-6.18
```

Output: `drivers/input/touchscreen/sitronix_ts_i2c.ko`

### Load

```bash
# If mainline st1232_ts is loaded, unload it first:
rmmod st1232_ts 2>/dev/null || true

insmod drivers/input/touchscreen/sitronix_ts_i2c.ko
```

### Install

```bash
make install  # runs modules_install under KDIR
```

---

## How it works

### Probe sequence

1. Validate I²C functionality.
2. Request `rst-gpio` (output) and `irq-gpio` (input) from DT.
3. Hardware reset the IC (RST low 20 ms → high, settle 50 ms).
4. Read IC capabilities in sequence:
   - `XY_RESOLUTION_HIGH` → `resolution_x`, `resolution_y`
   - `CHIP_ID` → `chip_id`, `Num_X`, `Num_Y`
   - `FIRMWARE_REVISION_3..0` → `fw_revision[4]`
   - `I2C_PROTOCOL` → `protocol_type` (A-type or B-type)
   - `MAX_NUM_TOUCHES` → `max_touches` (capped at 10)
5. Determine `pixel_length` per touch (5 bytes A-type, 3 bytes B-type).
6. Allocate and register input device with MT slots, resolution from IC.
7. Register threaded IRQ on falling edge.

### Report packet (read from `FINGERS` register)

```
byte  0   : [3:0] finger count
byte  1   : KEYS_REG – capacitive keys (BACK/HOME/MENU on bits 0-2)
bytes 2+  : per-touch, pixel_length bytes each
```

**A-type per touch (5 bytes):**

```
[0]: valid(7) x_h[6:4] y_h[2:0]
[1]: x_l
[2]: y_l
[3]: z (pressure)
[4]: area (touch-major)
```

**B-type per touch (3 bytes):**

```
[0]: valid(7) x_h[6:4] y_h[2:0]
[1]: x_l
[2]: y_l
```

---

## TODO / next steps

- [ ] Determine exact Sitronix IC variant on your panel (check `dmesg` for
      `chip_id`, `protocol_type`, `resolution` log lines after `insmod`).
- [ ] If `resolution_x/y` come back 0, set them explicitly in DTS or via
      `touchscreen-size-x` / `touchscreen-size-y` properties.
- [ ] Add `touchscreen-inverted-x`, `touchscreen-inverted-y` DTS support
      if panel orientation needs correction.
- [ ] Add firmware upgrade path (`/dev/sitronixDev` char device) if needed
      for panel reflashing.
- [ ] Consider upstreaming to `drivers/input/touchscreen/` once validated,
      using `sitronix,st1232`/`st1633` compatible strings for mainline.

---

## License

GPL-2.0-only — derived from Sitronix GPL reference driver.
