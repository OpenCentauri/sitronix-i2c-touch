/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * drivers/input/touchscreen/sitronix_ts_i2c.h
 *
 * Sitronix I2C Touchscreen driver - register map and protocol definitions
 * Ported from Sitronix vendor driver (C) 2011 Sitronix Technology Co., Ltd.
 * Adapted for Linux 6.18 out-of-tree by OpenCentauri.
 */
#ifndef __SITRONIX_TS_I2C_H
#define __SITRONIX_TS_I2C_H

#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/input.h>
#include <linux/input/mt.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/mutex.h>
#include <linux/module.h>

/* ---- driver identity --------------------------------------------------- */
#define SITRONIX_TS_NAME             "sitronixts"
#define SITRONIX_TS_I2C_DRVNAME      "sitronix_ts_i2c"
#define SITRONIX_TS_DESCRIPTION      "Sitronix Touchscreen Controller Driver"
#define SITRONIX_TOUCH_DRIVER_VERSION 0x03

/* ---- IC limits --------------------------------------------------------- */
#define SITRONIX_MAX_TOUCHES         10   /* absolute IC maximum          */

/* ---- stock-CC2 register offsets (16-bit addressed) --------------------- */
enum sitronix_reg {
	FIRMWARE_VERSION      = 0x0000,
	STATUS_REG            = 0x0001,
	DEVICE_CONTROL_REG    = 0x0002,
	X_RESOLUTION_LOW      = 0x0005,
	Y_RESOLUTION_LOW      = 0x0007,
	MAX_NUM_TOUCHES       = 0x0009,
	FIRMWARE_REVISION_3   = 0x000c,
	FIRMWARE_REVISION_2   = 0x000d,
	FIRMWARE_REVISION_1   = 0x000e,
	FIRMWARE_REVISION_0   = 0x000f,
	TOUCH_INFO            = 0x0010,
	TOUCH_POINT0          = 0x0014,
	MISC_CONTROL          = 0x00f0,
	CUSTOMER_INFO         = 0x00f1,
	SMART_WAKE_UP_REG     = 0x00f2,
	CHIP_ID               = 0x00f4,
	PAGE_REG              = 0x00ff,
};

#define STX_STATUS_READY_MASK   0x0f
#define STX_TOUCH_UPDATE_BIT    0x08
#define STX_TOUCH_VALID_BIT     0x80
#define STX_COORD_H_MASK        0x3f
#define STX_TOUCH_POINT_BYTES   7

/* ---- I2C protocol types ------------------------------------------------ */
enum sitronix_protocol_type {
	SITRONIX_STOCK_CC2_TYPE = 0,
};

/* ---- private driver state ---------------------------------------------- */
struct sitronix_ts {
	struct i2c_client  *client;
	struct input_dev   *input;
	struct mutex        lock;

	/* DT-provided GPIOs */
	int           irq_gpio;
	int           rst_gpio;

	/* IC capabilities (read from registers at probe) */
	uint8_t  fw_revision[4];
	int      resolution_x;
	int      resolution_y;
	uint8_t  max_touches;
	uint8_t  chip_id;
	uint8_t  protocol_type;   /* sitronix_protocol_type */
	uint8_t  pixel_length;    /* bytes per touch in packet */
	u8       Num_X;
	u8       Num_Y;

	bool     suspended;
};

#endif /* __SITRONIX_TS_I2C_H */
