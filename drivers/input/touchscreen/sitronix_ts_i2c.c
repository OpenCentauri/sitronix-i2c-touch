// SPDX-License-Identifier: GPL-2.0-only
/*
 * drivers/input/touchscreen/sitronix_ts_i2c.c
 *
 * Sitronix I2C Touchscreen Controller Driver
 * Target: Linux 6.18, out-of-tree .ko
 *
 * Compatible: "sitronixts" (matches DTS node sitronix55@55)
 *
 * Derived from Sitronix vendor driver
 *   (C) 2011 Sitronix Technology Co., Ltd. <rudy_huang@sitronix.com.tw>
 * Adapted and modernised for Linux 6.18 by OpenCentauri.
 */

#include "sitronix_ts_i2c.h"
#include <linux/version.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/pm_runtime.h>

#define DRIVER_AUTHOR  "OpenCentauri / Sitronix Technology Co., Ltd."
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(SITRONIX_TS_DESCRIPTION);
MODULE_LICENSE("GPL v2");

/* ======================================================================== */
/* Low-level I2C helpers                                                     */
/* ======================================================================== */

static int stx_i2c_read(struct i2c_client *client, u8 reg, u8 *buf, int len)
{
	int ret;

	ret = i2c_master_send(client, &reg, 1);
	if (ret < 0) {
		dev_err(&client->dev, "i2c write reg 0x%02x failed: %d\n", reg, ret);
		return ret;
	}
	ret = i2c_master_recv(client, buf, len);
	if (ret < 0) {
		dev_err(&client->dev, "i2c read reg 0x%02x failed: %d\n", reg, ret);
		return ret;
	}
	return 0;
}

static int stx_i2c_write(struct i2c_client *client, u8 *buf, int len)
{
	int ret = i2c_master_send(client, buf, len);
	if (ret < 0)
		dev_err(&client->dev, "i2c write failed: %d\n", ret);
	return (ret < 0) ? ret : 0;
}

/* ======================================================================== */
/* IC initialisation: read chip capabilities                                 */
/* ======================================================================== */

static int stx_get_resolution(struct sitronix_ts *ts)
{
	u8 buf[3];
	int ret;

	ret = stx_i2c_read(ts->client, XY_RESOLUTION_HIGH, buf, 3);
	if (ret < 0)
		return ret;

	ts->resolution_x = ((buf[0] & (X_RES_H_BMSK << X_RES_H_SHFT)) << 4) | buf[1];
	ts->resolution_y = ((buf[0] &  Y_RES_H_BMSK) << 8) | buf[2];

	dev_info(&ts->client->dev, "resolution: %d x %d\n",
		 ts->resolution_x, ts->resolution_y);
	return 0;
}

static int stx_get_chip_id(struct sitronix_ts *ts)
{
	u8 buf[3];
	int ret;

	ret = stx_i2c_read(ts->client, CHIP_ID, buf, 3);
	if (ret < 0)
		return ret;

	if (buf[0] == 0)
		ts->chip_id = (buf[1] + buf[2] > 32) ? 2 : 0;
	else
		ts->chip_id = buf[0];

	ts->Num_X = buf[1];
	ts->Num_Y = buf[2];

	dev_info(&ts->client->dev, "chip_id=%d Num_X=%d Num_Y=%d\n",
		 ts->chip_id, ts->Num_X, ts->Num_Y);
	return 0;
}

static int stx_get_fw_revision(struct sitronix_ts *ts)
{
	int ret = stx_i2c_read(ts->client, FIRMWARE_REVISION_3,
				 ts->fw_revision, 4);
	if (ret < 0)
		return ret;

	dev_info(&ts->client->dev, "fw_revision: %02x %02x %02x %02x\n",
		 ts->fw_revision[0], ts->fw_revision[1],
		 ts->fw_revision[2], ts->fw_revision[3]);
	return 0;
}

static int stx_get_protocol_type(struct sitronix_ts *ts)
{
	u8 buf[1];
	int ret;

	if (ts->chip_id <= 3) {
		ret = stx_i2c_read(ts->client, I2C_PROTOCOL, buf, 1);
		if (ret < 0)
			return ret;
		ts->protocol_type = buf[0] & I2C_PROTOCOL_BMSK;
	} else {
		/* chip_id > 3: always A-type */
		ts->protocol_type = SITRONIX_A_TYPE;
	}

	dev_info(&ts->client->dev, "protocol_type=%d\n", ts->protocol_type);
	return 0;
}

static int stx_get_max_touches(struct sitronix_ts *ts)
{
	u8 buf[1];
	int ret;

	ret = stx_i2c_read(ts->client, MAX_NUM_TOUCHES, buf, 1);
	if (ret < 0)
		return ret;

	ts->max_touches = min_t(u8, buf[0], SITRONIX_MAX_TOUCHES);
	dev_info(&ts->client->dev, "max_touches=%d\n", ts->max_touches);
	return 0;
}

static int stx_init_ic(struct sitronix_ts *ts)
{
	int ret;

	ret = stx_get_resolution(ts);
	if (ret < 0) return ret;

	ret = stx_get_chip_id(ts);
	if (ret < 0) return ret;

	ret = stx_get_fw_revision(ts);
	if (ret < 0) return ret;

	ret = stx_get_protocol_type(ts);
	if (ret < 0) return ret;

	ret = stx_get_max_touches(ts);
	if (ret < 0) return ret;

	/*
	 * Vendor quirk: if fw_revision bytes 0-1 are both 0 and protocol
	 * type is RESERVED, force B-type (older panels).
	 */
	if ((ts->fw_revision[0] == 0) && (ts->fw_revision[1] == 0) &&
	    (ts->protocol_type == SITRONIX_RESERVED_TYPE_0)) {
		ts->protocol_type = SITRONIX_B_TYPE;
		dev_info(&ts->client->dev, "protocol forced to B-type\n");
	}

	if (ts->protocol_type == SITRONIX_A_TYPE) {
		ts->pixel_length = PIXEL_DATA_LENGTH_A;
	} else {
		/* B-type: 3-byte packets, max 2 touches */
		ts->pixel_length = PIXEL_DATA_LENGTH_B;
		ts->max_touches  = 2;
		dev_info(&ts->client->dev, "B-type: max_touches clamped to 2\n");
	}

	return 0;
}

/* ======================================================================== */
/* Hardware reset                                                             */
/* ======================================================================== */

static void stx_hw_reset(struct sitronix_ts *ts)
{
	if (!gpio_is_valid(ts->rst_gpio))
		return;

	gpio_direction_output(ts->rst_gpio, 0);
	msleep(20);
	gpio_set_value(ts->rst_gpio, 1);
	msleep(50);
	dev_dbg(&ts->client->dev, "hw reset done\n");
}

/* ======================================================================== */
/* Touch reporting                                                            */
/* ======================================================================== */

/*
 * Sensor keys: the KEYS_REG byte carries up to 3 capacitive buttons
 * mapped to BACK (bit0), HOME (bit1), MENU (bit2).
 */
static const struct sitronix_sensor_key stx_keys[] = {
	{ KEY_BACK },
	{ KEY_HOME },
	{ KEY_MENU },
};
#define STX_NUM_KEYS ARRAY_SIZE(stx_keys)

static void stx_report_sensor_keys(struct sitronix_ts *ts, u8 cur)
{
	struct input_dev *input = ts->input;
	int i;

	for (i = 0; i < STX_NUM_KEYS; i++) {
		bool was = (ts->prev_key_status >> i) & 1;
		bool is  = (cur >> i) & 1;

		if (is && !was)
			input_report_key(input, stx_keys[i].code, 1);
		else if (!is && was)
			input_report_key(input, stx_keys[i].code, 0);
	}
	ts->prev_key_status = cur;
}

/*
 * stx_report_touches - parse a raw report packet and push MT events.
 *
 * Packet layout starting at FINGERS register:
 *   byte  0  : [7:4] = don't care, [3:0] = finger count
 *   byte  1  : KEYS_REG  (capacitive sensor keys)
 *   bytes 2+ : per-touch data, pixel_length bytes each
 *
 * A-type per-touch (5 bytes):
 *   [0]: valid(7) x_h(6:4) y_h(2:0)
 *   [1]: x_l
 *   [2]: y_l
 *   [3]: z (pressure)
 *   [4]: area
 *
 * B-type per-touch (3 bytes):
 *   [0]: valid(7) x_h(6:4) y_h(2:0)
 *   [1]: x_l
 *   [2]: y_l
 */
static void stx_report_touches(struct sitronix_ts *ts)
{
	struct i2c_client *client = ts->client;
	struct input_dev  *input  = ts->input;
	int buf_len;
	u8 *buf;
	u8 fingers;
	u8 key_status;
	int i, slot;
	int ret;

	/*
	 * Read FINGERS + KEYS_REG + all touch data in one shot:
	 *   2 header bytes + max_touches * pixel_length
	 */
	buf_len = 2 + ts->max_touches * ts->pixel_length;
	buf = kzalloc(buf_len, GFP_KERNEL);
	if (!buf)
		return;

	ret = stx_i2c_read(client, FINGERS, buf, buf_len);
	if (ret < 0)
		goto out;

	fingers    = buf[0] & FINGERS_BMSK;
	key_status = buf[1];

	if (fingers > ts->max_touches)
		fingers = ts->max_touches;

	/* Report all MT slots */
	for (slot = 0; slot < ts->max_touches; slot++) {
		const u8 *p = &buf[2 + slot * ts->pixel_length];
		bool valid;
		u16  x, y;

		valid = (p[0] >> X_COORD_VALID_SHFT) & X_COORD_VALID_BMSK;
		x = (u16)(((p[0] >> X_COORD_H_SHFT) & X_COORD_H_BMSK) << 8) | p[1];
		y = (u16)((p[0] & Y_COORD_H_BMSK) << 8) | p[2];

		input_mt_slot(input, slot);

		if (valid && (slot < fingers)) {
			input_mt_report_slot_state(input, MT_TOOL_FINGER, true);
			input_report_abs(input, ABS_MT_POSITION_X, x);
			input_report_abs(input, ABS_MT_POSITION_Y, y);
			if (ts->pixel_length >= PIXEL_DATA_LENGTH_A) {
				input_report_abs(input, ABS_MT_PRESSURE,     p[3]);
				input_report_abs(input, ABS_MT_TOUCH_MAJOR,  p[4]);
			}
		} else {
			input_mt_report_slot_state(input, MT_TOOL_FINGER, false);
		}
	}

	input_mt_report_pointer_emulation(input, false);

	/* Sensor keys */
	for (i = 0; i < STX_NUM_KEYS; i++)
		input_set_capability(input, EV_KEY, stx_keys[i].code);
	stx_report_sensor_keys(ts, key_status);

	input_sync(input);

out:
	kfree(buf);
}

/* ======================================================================== */
/* Threaded IRQ handler                                                       */
/* ======================================================================== */

static irqreturn_t sitronix_ts_irq_thread(int irq, void *dev_id)
{
	struct sitronix_ts *ts = dev_id;

	mutex_lock(&ts->lock);
	if (!ts->suspended)
		stx_report_touches(ts);
	mutex_unlock(&ts->lock);

	return IRQ_HANDLED;
}

/* ======================================================================== */
/* Power management                                                           */
/* ======================================================================== */

static int sitronix_ts_suspend(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct sitronix_ts *ts    = i2c_get_clientdata(client);
	u8 buf[2];
	int ret;

	mutex_lock(&ts->lock);
	ts->suspended = true;
	disable_irq(client->irq);

	/* set power-down bit in DEVICE_CONTROL_REG */
	ret = stx_i2c_read(client, DEVICE_CONTROL_REG, &buf[1], 1);
	if (ret == 0) {
		buf[0] = DEVICE_CONTROL_REG;
		buf[1] |= 0x02;
		stx_i2c_write(client, buf, 2);
	}

	mutex_unlock(&ts->lock);
	return 0;
}

static int sitronix_ts_resume(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct sitronix_ts *ts    = i2c_get_clientdata(client);
	u8 buf[2];
	int ret;

	mutex_lock(&ts->lock);

	/* clear power-down bit */
	ret = stx_i2c_read(client, DEVICE_CONTROL_REG, &buf[1], 1);
	if (ret == 0) {
		buf[0] = DEVICE_CONTROL_REG;
		buf[1] &= ~0x02;
		stx_i2c_write(client, buf, 2);
	}

	stx_hw_reset(ts);
	ts->suspended = false;
	enable_irq(client->irq);

	mutex_unlock(&ts->lock);
	return 0;
}

static SIMPLE_DEV_PM_OPS(sitronix_ts_pm_ops,
			 sitronix_ts_suspend,
			 sitronix_ts_resume);

/* ======================================================================== */
/* Probe / remove                                                             */
/* ======================================================================== */

static int sitronix_ts_probe(struct i2c_client *client)
{
	struct device *dev = &client->dev;
	struct sitronix_ts *ts;
	struct input_dev   *input;
	int ret;

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
		dev_err(dev, "I2C_FUNC_I2C not supported\n");
		return -ENODEV;
	}

	ts = devm_kzalloc(dev, sizeof(*ts), GFP_KERNEL);
	if (!ts)
		return -ENOMEM;

	ts->client = client;
	mutex_init(&ts->lock);
	i2c_set_clientdata(client, ts);

	/* ---- GPIO setup ---------------------------------------------------- */
	ts->irq_gpio = of_get_named_gpio(dev->of_node, "irq-gpio", 0);
	ts->rst_gpio = of_get_named_gpio(dev->of_node, "rst-gpio", 0);

	if (gpio_is_valid(ts->rst_gpio)) {
		ret = devm_gpio_request_one(dev, ts->rst_gpio,
					    GPIOF_OUT_INIT_HIGH, "sitronix_rst");
		if (ret) {
			dev_err(dev, "failed to request rst-gpio: %d\n", ret);
			return ret;
		}
	}

	if (gpio_is_valid(ts->irq_gpio)) {
		ret = devm_gpio_request_one(dev, ts->irq_gpio,
					    GPIOF_IN, "sitronix_irq");
		if (ret) {
			dev_err(dev, "failed to request irq-gpio: %d\n", ret);
			return ret;
		}
		if (!client->irq)
			client->irq = gpio_to_irq(ts->irq_gpio);
	}

	if (!client->irq) {
		dev_err(dev, "no IRQ assigned\n");
		return -EINVAL;
	}

	/* ---- Reset IC ------------------------------------------------------ */
	stx_hw_reset(ts);

	/* ---- Read IC capabilities ------------------------------------------ */
	ret = stx_init_ic(ts);
	if (ret < 0) {
		dev_err(dev, "IC init failed: %d\n", ret);
		return ret;
	}

	/* Validate resolution; fall back to safe defaults if IC reports 0 */
	if (ts->resolution_x == 0 || ts->resolution_y == 0) {
		dev_warn(dev, "IC reported 0 resolution; using 800x480 defaults\n");
		ts->resolution_x = 800;
		ts->resolution_y = 480;
	}
	if (ts->max_touches == 0) {
		dev_warn(dev, "IC reported 0 max_touches; using 5\n");
		ts->max_touches = 5;
	}

	/* ---- Input device -------------------------------------------------- */
	input = devm_input_allocate_device(dev);
	if (!input)
		return -ENOMEM;

	ts->input        = input;
	input->name      = "Sitronix I2C Touchscreen";
	input->phys      = "sitronix_ts/input0";
	input->id.bustype = BUS_I2C;
	input->dev.parent = dev;

	input_set_capability(input, EV_ABS, ABS_X);
	input_set_capability(input, EV_ABS, ABS_Y);
	input_set_capability(input, EV_KEY, BTN_TOUCH);

	input_set_abs_params(input, ABS_X,
			     0, ts->resolution_x - 1, 0, 0);
	input_set_abs_params(input, ABS_Y,
			     0, ts->resolution_y - 1, 0, 0);
	input_set_abs_params(input, ABS_MT_POSITION_X,
			     0, ts->resolution_x - 1, 0, 0);
	input_set_abs_params(input, ABS_MT_POSITION_Y,
			     0, ts->resolution_y - 1, 0, 0);
	input_set_abs_params(input, ABS_MT_PRESSURE,     0, 255, 0, 0);
	input_set_abs_params(input, ABS_MT_TOUCH_MAJOR,  0, 255, 0, 0);

	ret = input_mt_init_slots(input, ts->max_touches, INPUT_MT_DIRECT);
	if (ret) {
		dev_err(dev, "input_mt_init_slots failed: %d\n", ret);
		return ret;
	}

	for (i = 0; i < STX_NUM_KEYS; i++)
		input_set_capability(input, EV_KEY, stx_keys[i].code);

	input_set_drvdata(input, ts);

	ret = input_register_device(input);
	if (ret) {
		dev_err(dev, "input_register_device failed: %d\n", ret);
		return ret;
	}

	/* ---- Threaded IRQ -------------------------------------------------- */
	ret = devm_request_threaded_irq(dev, client->irq,
					NULL, sitronix_ts_irq_thread,
					IRQF_ONESHOT | IRQF_TRIGGER_FALLING,
					SITRONIX_TS_I2C_DRVNAME, ts);
	if (ret) {
		dev_err(dev, "request_threaded_irq failed: %d\n", ret);
		return ret;
	}

	dev_info(dev, "Sitronix touchscreen probed (chip_id=%d proto=%d res=%dx%d mt=%d)\n",
		 ts->chip_id, ts->protocol_type,
		 ts->resolution_x, ts->resolution_y, ts->max_touches);
	return 0;
}

static void sitronix_ts_remove(struct i2c_client *client)
{
	/* devm resources (IRQ, GPIOs, input dev) released automatically */
	dev_info(&client->dev, "Sitronix touchscreen removed\n");
}

/* ======================================================================== */
/* DT / I2C tables and driver registration                                   */
/* ======================================================================== */

static const struct of_device_id sitronix_ts_of_match[] = {
	{ .compatible = "sitronixts" },
	{ .compatible = "sitronix,st1232" },
	{ .compatible = "sitronix,st1633" },
	{ },
};
MODULE_DEVICE_TABLE(of, sitronix_ts_of_match);

static const struct i2c_device_id sitronix_ts_id[] = {
	{ "sitronixts", 0 },
	{ "sitronix_ts_i2c", 0 },
	{ },
};
MODULE_DEVICE_TABLE(i2c, sitronix_ts_id);

static struct i2c_driver sitronix_ts_i2c_driver = {
	.driver = {
		.name           = SITRONIX_TS_I2C_DRVNAME,
		.of_match_table = sitronix_ts_of_match,
		.pm             = &sitronix_ts_pm_ops,
	},
	.probe    = sitronix_ts_probe,
	.remove   = sitronix_ts_remove,
	.id_table = sitronix_ts_id,
};

static int __init sitronix_ts_i2c_init(void)
{
	return i2c_add_driver(&sitronix_ts_i2c_driver);
}
module_init(sitronix_ts_i2c_init);

static void __exit sitronix_ts_i2c_exit(void)
{
	i2c_del_driver(&sitronix_ts_i2c_driver);
}
module_exit(sitronix_ts_i2c_exit);
