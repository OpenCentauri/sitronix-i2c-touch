# SPDX-License-Identifier: GPL-2.0
#
# Out-of-tree Makefile for sitronix_ts_i2c.ko
#
# Usage (native):
#   make
#
# Usage (cross-compile for ARM32 hard-float / Allwinner R528):
#   make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- \
#        KDIR=/path/to/linux-6.18
#
# The resulting sitronix_ts_i2c.ko is placed in
# drivers/input/touchscreen/ relative to this directory.

obj-m += drivers/input/touchscreen/sitronix_ts_i2c.o

KDIR ?= /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

install:
	$(MAKE) -C $(KDIR) M=$(PWD) modules_install
