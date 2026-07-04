# CC2 Stock Kernel Analysis — Sitronix I2C Touch Driver

## Source files

- `/home/paul/carbon/cc-fw-tools-cc2/unpacked2/kernel` — Android boot image extracted from stock CC2 firmware (`01.03.01.89`).
- `/home/paul/carbon/cc2-firmware/stock/kernel-01.03.01.89` — same kernel binary as the Android boot image payload (SHA256 identical).

## What was found

### 1. Android boot image structure

`cc-fw-tools-cc2/unpacked2/kernel` is an Android boot image (`ANDROID!` magic) with:

| Field | Value |
|---|---|
| kernel size | 3,972,880 bytes (0x3c9f10) |
| kernel load address | 0x40008000 |
| ramdisk size | 12 bytes |
| ramdisk load address | 0x41000000 |
| page size | 2048 |
| header version | 0 |

The kernel payload begins at byte **0x800** (after the 2 KiB header) and is a standard ARM **zImage**.

### 2. zImage payload structure

The zImage header (magic `0x016f2818` at offset 0x24) indicates a compressed payload from the start of the file to the end of the zImage (`0x3c9f10`).

`binwalk` found a single gzip stream at **0x3e0c** with a decompressed size of **10,730,880 bytes**. The gzip stream itself decompresses to the same file we already had (`kernel-01.03.01.89`). This means:

- The outer zImage's gzip payload is the **inner uncompressed kernel image**.
- That inner image is a **raw ARM kernel Image** (not a zImage), but it still starts with executable ARM instructions.
- The first 0x1000 bytes appear to be the boot wrapper / decompressor stub, followed by the uncompressed kernel code and data.

### 3. Decompression result

The inner `kernel-01.03.01.89` (10,730,880 bytes) is the decompressed kernel. It contains readable strings:

- `Linux version 5.4.61 (3dp@user-07) ... #500 SMP PREEMPT Fri Dec 26 11:38:31 UTC 2025`
- `CONFIG_TOUCHSCREEN_SITRONIX_I2C_TOUCH=y`
- `sitronix_ts_i2c_init`, `sitronix_ts_i2c_exit`, `sitronix_ts_i2c_probe`
- `Sitronix I2C Touchscreen`
- `Sitronix touch`

The Sitronix driver is **built into the kernel** (`=y`), not a module.

### 4. Why full disassembly was not achieved

The inner kernel image is **not an ELF file** and has no symbol table. To extract the exact `sitronix_ts_i2c_probe` / `sitronix_ts_i2c_init` code from this raw image, we would need one of:

- The **load address** of the kernel in physical memory, so we can disassemble the raw image at the correct offset and locate the driver by cross-referencing string addresses.
- A **kallsyms** / symbol table extracted from a running stock CC2 system (`/proc/kallsyms`, `System.map`, or a `vmlinux` from the vendor).
- A **decompiler** pass (Binary Ninja / Ghidra) with the correct ARM base address and manual symbol annotation.

None of these were available in the current filesystem.

## What the device tree says

`/home/paul/carbon/cc2-firmware/stock/kernel_config.dts` (and `/home/paul/carbon/cc-fw-tools-cc2/uboot/kernel_config.dts`) decompiled from the same firmware gives the touchscreen node:

```dts
&twi2 {
    status = "okay";
    pinctrl-names = "default";
    pinctrl-0 = <&twi2_pins>;
    /* ... */
    sitronix_ts@55 {
        compatible = "sitronix_ts";
        reg = <0x55>;
        interrupt-parent = <&pio>;
        interrupts = <4 1 IRQ_TYPE_LEVEL_LOW>;  /* PE1, level-low */
        /* rst/wakeup GPIO on PE0 in the original stock firmware */
    };
};
```

Key observations:

- **Address `0x55`** — confirmed Sitronix.
- **IRQ type `IRQ_TYPE_LEVEL_LOW`** — the stock DT uses level-low, not edge.
- **Reset/wakeup GPIO** is on PE0 (active-high in the stock driver).

## Current Cosmos/Yocto driver status (as of this session)

We deployed the OpenCentauri `sitronix-i2c-touch` recipe and DTB on a CC2 running kernel 6.18.37. After reboot:

- The driver probes and registers `/dev/input/touchscreen0`.
- `dmesg` shows `chip_id=0`, `resolution: 0 x 0`, `max_touches=0` — the driver reads all-zero identity/capability registers and falls back to defaults.
- IRQ counter is essentially flat; one IRQ was observed during a 20-second touch window, but no input events and no non-zero coordinate registers.
- Direct `i2cget` polling of status (`0x01`) and coordinates (`0x0c/0x0d`, `0x0e/0x0f`) returns `0x00` even while touching.

## Hypothesis from this stock-kernel inspection

The stock firmware uses a **vendor-specific Sitronix driver** (`sitronix_ts`) built into the kernel and a **level-low IRQ on PE1**. The current Cosmos/Yocto driver is either:

1. Not initializing the controller correctly (reset/power-up sequence differs from the vendor driver), or
2. Using the wrong IRQ trigger type (edge vs level-low), or
3. Not toggling the reset/wakeup GPIO at the right time/at all, leaving the controller in an unresponsive state even though it ACKs I²C transactions enough to bind.

## Recommended next steps

1. **Capture the exact GPIO/reset sequence from the vendor driver.**
   - Get the `vmlinux` or `System.map` from the stock system (or from the vendor's GPL source drop if available).
   - Or boot the stock firmware and dump `/proc/kallsyms` and `/proc/interrupts` to confirm the IRQ handler mapping and the reset GPIO usage.

2. **Fix the Cosmos/Yocto DTB and driver.**
   - Ensure the DTB uses `IRQ_TYPE_LEVEL_LOW` for the touchscreen interrupt (not edge).
   - Ensure the reset GPIO (PE0) is correctly described and asserted/de-asserted during probe.
   - Compare `sitronix_ts_i2c_probe` between the vendor source and the current OpenCentauri `sitronix-i2c-touch` fork to identify missing initialization steps.

3. **Verify the fix with the live test ladder.**
   - After reboot, check `dmesg` for non-zero `chip_id`, resolution, and `max_touches`.
   - Run the IRQ-delta test, `evtest` touch/slide, and direct `i2cget` coordinate sampling as documented in the Cosmos skill.

## References

- Cosmos skill: `devops/cosmos` → `SKILL.md`, section "CC2 touchscreen" and `references/cc2-sitronix-live-driver-test-loop.md`
- Stock DTB: `/home/paul/carbon/cc2-firmware/stock/kernel_config.dts`
- Stock kernel Android boot image: `/home/paul/carbon/cc-fw-tools-cc2/unpacked2/kernel`
- Stock kernel raw binary: `/home/paul/carbon/cc2-firmware/stock/kernel-01.03.01.89`
