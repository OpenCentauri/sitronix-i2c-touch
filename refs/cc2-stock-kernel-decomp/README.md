# CC2 stock kernel Sitronix decomp

Source copied from local analysis drop:
- `/home/paul/carbon/cosmos/sitronix_stock_decomp.c`

Why this matters:
- Confirms the stock CC2 driver uses **16-bit register-address I2C reads/writes** (`sitronix_ts_i2c_read` sends high byte + low byte)
- Confirms stock status/info reads at `0x0001`, `0x0005`, `0x0009`, `0x000c`, `0x00f4`
- Confirms the live report buffer is read from `0x0010`
- Confirms touch contacts are decoded as **7-byte records** with the valid bit at `0x80`

This is the best local reference for matching stock CC2 behavior while keeping the out-of-tree driver minimal.
