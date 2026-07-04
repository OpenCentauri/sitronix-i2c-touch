# ST77922 Touch Driver Reference

Source: https://github.com/Beast12/jarvis-voice-assistant-freenove/blob/main/lib/TFT_eSPI/ST77922_Touch.cpp

Key observations for CC2 comparison:

- I2C address: 0x55 (same as our target)
- Register addresses are **16-bit** (e.g. STATUS 0x0001, TOUCH_INFO 0x0010, TOUCH_POINT0 0x0014)
- Init waits for STATUS & 0x0F to become 0, then reads MAX_TOUCHES (0x0009)
- Touch point data: 7 bytes per point, valid bit in byte 0 bit 7
- Reset: 100ms low, 100ms high
- Default panel: 320x480

This differs from our current 8-bit-address Sitronix driver. The stock CC2
kernel uses `compatible = "sitronix_ts"` and the same I2C address, so it may
use a hybrid protocol or the ST77922 may be a 16-bit-address variant of the
same family. Copied here for cross-reference while decompiling the stock
kernel.
