# CC2 Stock Sitronix Touchscreen Analysis

Date: 2026-07-04
Stock device: 10.10.10.178 (Android/TinaLinux kernel 5.4.61)
Cosmos device: 141 (TBD - root access needed)

## 1. Stock kernel facts from live system

From `/sys/kernel/debug/gpio`:
```
gpio-128 (st_rst_gpio) out hi
gpio-129 (st_irq_gpio) in  hi IRQ
```

From `/sys/kernel/debug/pinctrl/pio/pinmux-pins`:
```
pin 32 (PB0): device 2502800.twi function twi2 group PB0
pin 33 (PB1): device 2502800.twi function twi2 group PB1
```

TWI2 = I2C bus 2, on PB0/PB1. Touch controller at `2-0055`.

Input device present:
```
/sys/class/input/event0 -> .../2-0055/input/input0/event0
NAME="sitronix_ts_i2c"
```

## 2. Stock DTB node (extracted from `unpacked2/kernel` Android boot image)

```dts
sitronix@55 {
    compatible = "sitronix_ts";
    reg = <0x55>;
    interrupts = <4 1 8>;
    irq-gpio = <0x13 0x04>;
    reset-gpio = <0x13 0x05>;
};
```

Note: `0x13` is the phandle for `&pio`, so:
- `irq-gpio = <&pio 4 1>`   -> PE1 / gpio-129
- `reset-gpio = <&pio 4 0>` -> PE0 / gpio-128

`interrupts = <4 1 8>` is a 3-cell Allwinner GPIO interrupt:
- bank 4 = PE
- pin 1 = PE1
- trigger 8 = IRQ_TYPE_LEVEL_LOW

So the IRQ is **level-low**, not falling-edge.

## 3. Stock driver disassembly

Kernel base address for `objdump`: `0xc0008000`.
File offset = virtual address - 0xc0008000.

### 3.1 sitronix_ts_reset_device (0xc043c984 -> file 0x43c984)

```
c043c984: push {r4, lr}
c043c988: mov r4, r0
c043c98c: ldr r3, [r0, #16]
c043c990: ldr r0, [r3, #12]
c043c994: bl 0xc0343dec   ; gpio_to_desc? gpio_get?
c043c998: mov r1, #0      ; direction output, value 0
c043c99c: bl 0xc0342fec   ; gpiod_direction_output?
c043c9a0: mov r0, #1      ; msleep(1)
c043c9a4: bl 0xc016da20   ; msleep
c043c9a8: ldr r3, [r4, #16]
c043c9ac: ldr r0, [r3, #12]
c043c9b0: bl 0xc0343dec   ; gpio_to_desc again
c043c9b4: mov r1, #1      ; value 1
c043c9b8: bl 0xc0342fec   ; gpiod_direction_output
c043c9bc: mov r0, #100    ; msleep(100)
c043c9c0: bl 0xc016da20   ; msleep
c043c9c4: mov r0, #0
c043c9c8: pop {r4, pc}
```

Reset sequence: **low 1ms, high 100ms**.

### 3.2 sitronix_ts_i2c_probe (0xc043d794 -> file 0x43d794)

Parses `irq-gpio` and `reset-gpio` from DT, then calls `sitronix_ts_probe`.
The disassembly shows it stores the parsed GPIOs in the device struct at offsets
that are later used by `sitronix_ts_reset_device`.

### 3.3 sitronix_ts_probe (0xc043c9cc -> file 0x43c9cc)

Calls:
- `sitronix_ts_reset_device` (0xc043c984)
- `sitronix_ts_get_chip_id` (0xc043dadc)
- `sitronix_ts_get_device_status` (0xc043d9c4)
- `sitronix_ts_get_resolution` (0xc043eab0)
- `sitronix_ts_get_max_touches` (0xc043c2c4)
- input device registration
- IRQ request

Full disassembly is in `disasm-sitronix_ts_probe.txt`.

## 4. Live register capture (userland, racing with kernel driver)

Because the stock driver is bound to the I2C device, userland `i2cget` races
with the kernel. The captured values are not reliable. The only useful
observation is that `/dev/input/event0` is the Sitronix device and that the
touchscreen works (the UI receives touches).

Captured files:
- `i2c-poll-stock-20260704-102933.txt`
- `capture-sitronix-stock-20260704-103336.txt`
- `capture-sitronix-stock-20260704-103252.txt`
- `gpio-state-stock-20260704-093714.txt` etc.

## 5. Comparison with current Cosmos/Yocto driver

Current Cosmos driver: `drivers/input/touchscreen/sitronix_ts_i2c.c`

| Parameter | Stock | Cosmos | Fix needed |
|---|---|---|---|
| `compatible` | `"sitronix_ts"` | `"sitronixts"`, `"sitronix,st1232"` | add `"sitronix_ts"` |
| Reset DT property | `"reset-gpio"` | `"rst-gpio"` | change to `"reset-gpio"` or support both |
| Reset timing | low 1ms, high 100ms | low 20ms, high 50ms | align to 1ms/100ms |
| IRQ trigger | `IRQF_TRIGGER_LOW` | `IRQF_TRIGGER_FALLING` | change to `IRQF_TRIGGER_LOW` |
| Reset GPIO init | from DT | `GPIOF_OUT_INIT_HIGH` | keep current, but parse from right DT |

## 6. Proposed fixes

### 6.1 Driver (`sitronix_ts_i2c.c`)

1. Add `"sitronix_ts"` to `sitronix_ts_of_match[]`.
2. Change DT property lookup from `"rst-gpio"` to `"reset-gpio"`.
3. Change `IRQF_TRIGGER_FALLING` to `IRQF_TRIGGER_LOW`.
4. Align reset timing: 1ms low, 100ms high (or keep 20ms/50ms as safe over-estimate).

### 6.2 Device Tree

Add `reset-gpio` and `interrupts` to the `sitronix@55` node:

```dts
&twi2 {
    sitronix@55 {
        compatible = "sitronix_ts";
        reg = <0x55>;
        interrupts = <4 1 8>;
        irq-gpio = <&pio 4 1 GPIO_ACTIVE_LOW>;
        reset-gpio = <&pio 4 0 GPIO_ACTIVE_HIGH>;
    };
};
```

## 7. Files included

- `disasm-sitronix_ts_i2c_probe.txt`
- `disasm-sitronix_ts_probe.txt`
- `disasm-sitronix_ts_reset_device.txt`
- `disasm-sitronix_ts_i2c_init.txt`
- `disasm-sitronix_ts_get_chip_id.txt`
- `disasm-sitronix_ts_get_device_status.txt`
- `disasm-sitronix-region.txt`
- `poll-sitronix-stock.sh`
- `capture-sitronix-stock.sh`
- `i2c-poll-stock-20260704-102933.txt`
- `capture-sitronix-stock-20260704-103336.txt`
- `capture-sitronix-stock-20260704-103252.txt`
- `kallsyms-stock-20260704-092316.txt` (symbol addresses from /proc/kallsyms)
- `debug-gpio-stock-*.txt`
- `pinctrl-*-stock-*.txt`
- `clk-summary-stock-*.txt`
