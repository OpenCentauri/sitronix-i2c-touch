# CC2 stock kernel Sitronix decomp

This repository keeps two references for the stock CC2 Sitronix driver:

- [Original base radare2 decomp](./sitronix_stock_decomp.c)
- [Enhanced pseudo-c export](./cc2-kernel-01.03.01.89.sitronix.pdg.c) generated with [r2decomp](https://github.com/pdscomp/r2decomp) and the `r2ghidra` plugin

The enhanced output is the preferred reference when you want cleaner pseudo-c. The base radare2 decomp is still useful when you want a closer view of the raw decompiler output.

Why this matters:

- Confirms the stock CC2 driver uses **16-bit register-address I2C reads/writes** (`sitronix_ts_i2c_read` sends high byte + low byte)
- Confirms stock status/info reads at `0x0001`, `0x0005`, `0x0009`, `0x000c`, `0x00f4`
- Confirms the live report buffer is read from `0x0010`
- Confirms touch contacts are decoded as **7-byte records** with the valid bit at `0x80`
