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
├── drivers/
│   └── input/
│       └── touchscreen/
│           ├── Kconfig                       # Kconfig fragment
│           ├── sitronix_ts_i2c.h             # register map, structs (our driver)
│           └── sitronix_ts_i2c.c             # driver implementation (our driver)
└── refs/
    ├── README.md                              # refs map / organization
    ├── vendor-driver/                         # original Sitronix vendor .c/.h
    ├── st77922-touch-driver/                 # external ST77922 reference
    ├── cc2-stock-kernel-decomp/              # pseudo-C export from stock CC2 kernel
    └── cc2-stock-analysis/                   # stock captures, disasm, scripts
```

### Reference driver (`refs/vendor-driver/`)

[`refs/vendor-driver/sitronix_i2c_touch.c`](refs/vendor-driver/sitronix_i2c_touch.c) and
[`refs/vendor-driver/sitronix_i2c_touch.h`](refs/vendor-driver/sitronix_i2c_touch.h) are the original
Sitronix vendor driver (© 2011 Sitronix Technology Co., Ltd., GPL-2.0),
sourced from the CriticalLink MitySOM support site. They are kept here as
an unmodified reference for:

- Register map validation
- Protocol A/B packet layout reference
- Feature parity comparison (monitor thread, FW upgrade, sysfs, AA keys)
- Basis for any further porting work

**Do not build `refs/` directly** — it targets older kernels (~3.x) and will
not compile cleanly against 6.18 without the adaptations already applied in
`drivers/input/touchscreen/sitronix_ts_i2c.c`.

### Stock CC2 kernel decomp (`refs/cc2-stock-kernel-decomp/`)

[`refs/cc2-stock-kernel-decomp/sitronix_stock_decomp.c`](refs/cc2-stock-kernel-decomp/sitronix_stock_decomp.c)
is a pseudo-C export of the stock CC2 kernel Sitronix driver copied from the
local `cosmos/` analysis workspace.

Useful bits it confirms:

- register I/O is **16-bit addressed**
- stock status/device-info reads use `0x0001`, `0x0005`, `0x0009`, `0x000c`, `0x00f4`
- live report reads start at `0x0010`
- touch contacts decode as **7-byte records** with valid bit `0x80`

### Stock CC2 captures / disassembly (`refs/cc2-stock-analysis/`)

[`refs/cc2-stock-analysis/README.md`](refs/cc2-stock-analysis/README.md) indexes the
organized stock-device material:

- `disasm/` — disassembly, kallsyms extracts, DT node extracts, summary notes
- `runtime/` — GPIO/sysfs/input/i2c/irq/pinctrl captures from stock CC2
- `scripts/` — helper capture/poll scripts used during investigation

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
      for panel reflashing — see `refs/sitronix_i2c_touch.c` for the
      full ISP/ioctl implementation to port.
- [ ] Consider upstreaming to `drivers/input/touchscreen/` once validated,
      using `sitronix,st1232`/`st1633` compatible strings for mainline.

---

## License

GPL-2.0-only — derived from Sitronix GPL reference driver.
