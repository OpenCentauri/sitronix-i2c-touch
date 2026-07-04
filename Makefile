obj-m += sitronix_ts_i2c.o

# Simple out-of-tree build Makefile for Sitronix I2C touchscreen driver
# Usage (from kernel tree or with KDIR set):
#   make -C /path/to/linux-6.18 M=$(PWD) modules

KDIR ?= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
