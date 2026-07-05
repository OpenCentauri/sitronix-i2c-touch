#!/usr/bin/env bash
# Build sitronix-i2c-touch.ko against the cosmos 6.18.37 kernel build tree.
set -euo pipefail

KERNEL_BUILD=/home/paul/carbon/cosmos/build/tmp/work/elegoo_centauri_carbon2-poky-linux-gnueabi/linux-mainline/6.18.37/build
GCC=/home/paul/carbon/cosmos/build/tmp/sysroots-components/x86_64/gcc-cross-arm/usr/bin/arm-poky-linux-gnueabi
BINUTILS=/home/paul/carbon/cosmos/build/tmp/sysroots-components/x86_64/binutils-cross-arm/usr/bin/arm-poky-linux-gnueabi

# PATH must put cross binutils FIRST so `as` resolves to the cross assembler
# (gcc calls `as` by name, not via the full cross-prefix path).
PATH=$BINUTILS:$GCC:$PATH \
  make -C "$KERNEL_BUILD" \
    M="$PWD" \
    ARCH=arm \
    CROSS_COMPILE=arm-poky-linux-gnueabi- \
    CC=arm-poky-linux-gnueabi-gcc \
    LD=arm-poky-linux-gnueabi-ld.bfd \
    OBJCOPY=arm-poky-linux-gnueabi-objcopy \
    STRIP=arm-poky-linux-gnueabi-strip \
    HOSTCC=gcc \
    modules "$@"
