# Sitronix I2C Touchscreen Driver Notes

This document captures the analysis and design for integrating a Sitronix I2C touchscreen controller at address 0x55 on an Allwinner R528 (sun8iw20) SoC into a Linux 6.18 kernel, based on the discussion with the user.

## DTS context

The stock DTS for the board includes the following node on TWI2 (I2C controller at 0x2502800):

```dts
sitronix55 {
    compatible = "sitronixts";
    reg = <0x55>;
    interrupt-parent = <&pio>;
    interrupts = <4 1 8>;  // PB4
    irq-gpio = <&pio 4 1 0>;
    rst-gpio = <&pio 4 0 0>;
    status = "okay";
};
```

This indicates:

- A Sitronix touchscreen IC on I2C address 0x55.
- A custom compatible string `"sitronixts"` (not mainline `"sitronix,st1232"` or `"sitronix,st1633"`).
- Separate GPIOs for IRQ and RESET, both on bank PB.

These properties match the expectations of the vendor Sitronix I2C touchscreen drivers that use `irq_gpio` and `reset_gpio` fields populated from device tree.[cite:1]

## Candidate driver family

Mainline Linux ships `drivers/input/touchscreen/st1232.c` (`st1232_ts` module) for Sitronix ST1232 and ST1633 controllers. The DT binding is documented in `Documentation/devicetree/bindings/input/touchscreen/sitronix-st1232.txt` and requires `compatible = "sitronix,st1232"` or `"sitronix,st1633"` plus `reg` and `interrupts` properties.[cite:2]

However, the user reported that the mainline driver does not work correctly with their touchscreen, which is consistent with other field reports: the mainline driver implements only basic multitouch coordinate reporting and omits vendor-specific features (smart wake, key events, monitoring).[cite:3]

A more complete Sitronix I2C touchscreen driver exists as `sitronix_i2c_touch.c` plus `sitronix_i2c_touch.h`, distributed in various vendor kernels (e.g., CriticalLink MitySOM support, Qualcomm Android examples). This driver:

- Is authored by Sitronix and licensed under GPL.[cite:4]
- Exposes names like `SITRONIX_I2C_TOUCH_MT_INPUT_DEV_NAME "SITRONIX"` and a char device `sitronixDev`.
- Includes conditional support for Allwinner/Sunxi architectures and uses DT-provided GPIOs for reset and interrupt (`irq_gpio`, `reset_gpio`).[cite:5]
- Implements protocol discovery at runtime: chip ID, firmware revision, protocol type, resolution, and maximum touches.[cite:6]

Given the DTS and symbol names (`sitronix_ts_i2c_init`, `sitronix_ts_i2c_exit`) the closest match to the stock driver is a variant of this Sitronix vendor driver, not the mainline `st1232_ts`.

## Design goals for a standalone 6.18 driver

The requested driver should:

- Build as an out-of-tree module (.ko) against Linux 6.18.
- Bind to the DTS node with `compatible = "sitronixts"` and `reg = <0x55>`.
- Use the TWI2 controller (`twi@2502800`) on the Allwinner R528 SoC.
- Read `irq-gpio` and `rst-gpio` from DT and configure them for interrupt and reset.
- Report multi-touch events via the input subsystem using modern `input_mt` APIs.
- Avoid legacy early-suspend APIs and rely on standard PM ops.
- Keep protocol handling (register reads, coordinate parsing) close to Sitronix vendor behavior while trimming unneeded features.

## High-level driver architecture

### Core structures

We define a private driver data structure:

```c
struct sitronix_ts {
    struct i2c_client      *client;
    struct input_dev       *input;
    struct mutex            lock;
    struct work_struct      work;

    int                     irq_gpio;
    int                     rst_gpio;
    unsigned long           irq_flags;
    unsigned long           rst_flags;

    u16                     max_x;
    u16                     max_y;
    u8                      max_touches;

    bool                    suspended;
};
```

This mirrors the vendor driver's use of I2C client, input device, work queue for event handling, and DT-provided GPIOs. The resolution and max-touches are populated during probe by reading Sitronix registers.[cite:6]

### Device tree binding

We add a new binding (documented in the repo's `Documentation/` directory) with the following properties:

- `compatible`: must be `"sitronixts"`.
- `reg`: I2C address (0x55 in this case).
- `irq-gpio`: GPIO used for touch interrupt.
- `rst-gpio`: GPIO used to reset the controller.
- `interrupts` / `interrupt-parent`: standard DT interrupt wiring for the IRQ line.

The driver will use `of_get_named_gpio_flags()` to obtain `irq_gpio` and `rst_gpio` and `devm_gpio_request_one()` / `gpiod_direction_output()` or the newer `devm_gpiod_get_optional()` API for configuration on 6.18.[cite:5]

### Probe sequence

In `sitronix_ts_probe()`:

1. Validate the I2C adapter supports required functionality (`I2C_FUNC_I2C`).
2. Fetch and configure GPIOs (reset low, then high) to bring the IC out of reset.[cite:5]
3. Allocate and register an `input_dev`:
   - Set `EV_ABS` and `EV_KEY` as needed.
   - Configure ABS axes: `ABS_X`, `ABS_Y`, and `ABS_MT_POSITION_X/Y` ranges using `max_x`, `max_y`.
   - Initialize multi-touch slots via `input_mt_init_slots()`.
4. Request the IRQ via `devm_request_threaded_irq()` using the GPIO-backed interrupt line described by `interrupts` in the DTS.
5. Read chip ID and firmware revision to verify the controller responds and optionally log them.

This matches the vendor driver's basic initialization flow but uses modern resource-managed APIs and threaded IRQs suitable for 6.x kernels.[cite:6]

### Interrupt handling

The driver installs a threaded IRQ handler that:

- Reads the Sitronix touch data report from the IC over I2C.
- Parses the number of touches and their coordinates.
- Reports touches using the slot-based `input_mt` API (e.g., `input_mt_slot()`, `input_mt_report_slot_state()`).
- Calls `input_sync()` at the end of the frame.

This avoids polling and aligns with mainline touchscreen drivers.`

### Power management

Instead of early-suspend, we add optional PM ops:

```c
static int sitronix_ts_suspend(struct device *dev)
{
    struct sitronix_ts *ts = dev_get_drvdata(dev);
    ts->suspended = true;
    disable_irq(ts->client->irq);
    return 0;
}

static int sitronix_ts_resume(struct device *dev)
{
    struct sitronix_ts *ts = dev_get_drvdata(dev);
    ts->suspended = false;
    enable_irq(ts->client->irq);
    return 0;
}

static const struct dev_pm_ops sitronix_ts_pm_ops = {
    .suspend = sitronix_ts_suspend,
    .resume  = sitronix_ts_resume,
};
```

These are wired into the `i2c_driver` struct via `.driver.pm = &sitronix_ts_pm_ops`, making the driver compatible with system suspend/resume while avoiding deprecated early-suspend interfaces.

### Module integration

The driver is packaged as a standalone module under `drivers/input/touchscreen/` in the repo, but it builds out-of-tree against a configured Linux 6.18 tree. We provide:

- A `Makefile` that builds `sitronix_ts_i2c.ko`.
- A `Kconfig` snippet that declares `CONFIG_TOUCHSCREEN_SITRONIX_TS55` and depends on `I2C` and `INPUT_TOUCHSCREEN`.
- A top-level `README.md` and this `notes-sitronix-ts55.md` documenting usage.

The module init/exit symbols can be named `sitronix_ts_i2c_init` and `sitronix_ts_i2c_exit` to match the user's expectations.

## Next steps

The next step is to implement the actual driver source files (`sitronix_ts_i2c.c`, optional header), add the Kbuild glue, and push them to the GitHub repo so the user can build and test the module against their 6.18 kernel.
