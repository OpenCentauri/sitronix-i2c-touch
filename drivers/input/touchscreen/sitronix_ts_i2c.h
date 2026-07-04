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

/* ---- register offsets -------------------------------------------------- */
enum sitronix_reg {
	FIRMWARE_VERSION      = 0x00,
	STATUS_REG            = 0x01,
	DEVICE_CONTROL_REG    = 0x02,
	TIMEOUT_TO_IDLE_REG   = 0x03,
	XY_RESOLUTION_HIGH    = 0x04,
	X_RESOLUTION_LOW      = 0x05,
	Y_RESOLUTION_LOW      = 0x06,
	/* 0x07-0x08 reserved */
	DEVICE_CONTROL_REG2   = 0x09,
	/* 0x0A-0x0B reserved */
	FIRMWARE_REVISION_3   = 0x0C,
	FIRMWARE_REVISION_2   = 0x0D,
	FIRMWARE_REVISION_1   = 0x0E,
	FIRMWARE_REVISION_0   = 0x0F,
	FINGERS               = 0x10,
	KEYS_REG              = 0x11,
	XY0_COORD_H           = 0x12,
	X0_COORD_L            = 0x13,
	Y0_COORD_L            = 0x14,
	I2C_PROTOCOL          = 0x3E,
	MAX_NUM_TOUCHES       = 0x3F,
	DATA_0_HIGH           = 0x40,
	DATA_0_LOW            = 0x41,
	MISC_CONTROL          = 0xF1,
	SMART_WAKE_UP_REG     = 0xF2,
	CHIP_ID               = 0xF4,
	PAGE_REG              = 0xFF,
};

/* ---- resolution register bit fields ------------------------------------ */
#define X_RES_H_SHFT  4
#define X_RES_H_BMSK  0xF
#define Y_RES_H_SHFT  0
#define Y_RES_H_BMSK  0xF

/* ---- FINGERS register -------------------------------------------------- */
#define FINGERS_BMSK  0xF
#define FINGERS_SHFT  0

/* ---- coordinate packet bit fields -------------------------------------- */
#define X_COORD_VALID_SHFT  7
#define X_COORD_VALID_BMSK  0x1
#define X_COORD_H_SHFT      4
#define X_COORD_H_BMSK      0x7
#define Y_COORD_H_SHFT      0
#define Y_COORD_H_BMSK      0x7

/* ---- I2C protocol types ------------------------------------------------ */
enum sitronix_protocol_type {
	SITRONIX_RESERVED_TYPE_0 = 0,
	SITRONIX_A_TYPE          = 1,  /* 5-byte-per-touch, up to max_touches  */
	SITRONIX_B_TYPE          = 2,  /* 3-byte-per-touch, max 2 touches      */
};
#define I2C_PROTOCOL_BMSK  0x3
#define I2C_PROTOCOL_SHFT  0x0

#define PIXEL_DATA_LENGTH_A  5   /* bytes per touch, A-type packets */
#define PIXEL_DATA_LENGTH_B  3   /* bytes per touch, B-type packets */

/* ---- per-touch data (A-type layout) ------------------------------------ */
typedef struct {
	u8 y_h    : 3,
	   reserved: 1,
	   x_h    : 3,
	   valid  : 1;
	u8 x_l;
	u8 y_l;
	u8 z;         /* pressure / touch-major */
	u8 area;      /* touch width  */
} __packed xy_data_t;

/* ---- sensor-key helpers ------------------------------------------------ */
struct sitronix_sensor_key {
	unsigned int code;
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
	uint8_t  Num_X;
	uint8_t  Num_Y;

	u8       prev_key_status;

	bool     suspended;
};

#endif /* __SITRONIX_TS_I2C_H */
