// SPDX-License-Identifier: GPL-2.0
/*
 * Sitronix I2C Touchscreen driver (address 0x55)
 *
 * Out-of-tree module targeting Linux 6.18, wired to DTS node:
 *   sitronix55 {
 *       compatible = "sitronixts";
 *       reg = <0x55>;
 *       interrupt-parent = <&pio>;
 *       interrupts = <4 1 8>; // PB4
 *       irq-gpio = <&pio 4 1 0>;
 *       rst-gpio = <&pio 4 0 0>;
 *       status = "okay";
 *   };
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/input.h>
#include <linux/interrupt.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/gpio.h>
#include <linux/gpio/consumer.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/mutex.h>

#define SITRONIX_TS_NAME        "sitronixts"
#define SITRONIX_TS_I2C_DRVNAME "sitronix_ts_i2c"

/* Simple assumptions; can be refined by reading IC-specific registers */
#define SITRONIX_TS_MAX_TOUCHES 5
#define SITRONIX_TS_MAX_X       800
#define SITRONIX_TS_MAX_Y       480

struct sitronix_ts {
	struct i2c_client      *client;
	struct input_dev       *input;
	struct mutex            lock;
	int                     irq_gpio;
	int                     rst_gpio;
	unsigned long           irq_flags;
	unsigned long           rst_flags;
	bool                    suspended;
};

static int sitronix_ts_reset(struct sitronix_ts *ts)
{
	if (!gpio_is_valid(ts->rst_gpio))
		return 0;

	gpio_direction_output(ts->rst_gpio, 0);
	msleep(20);
	gpio_set_value(ts->rst_gpio, 1);
	msleep(50);

	return 0;
}

/* Placeholder: read one touch point and report via input subsystem.
 * Real implementation should parse Sitronix protocol frame. */
static int sitronix_ts_report(struct sitronix_ts *ts)
{
	/* TODO: implement I2C frame read and MT slot reporting. */
	return 0;
}

static irqreturn_t sitronix_ts_irq_thread(int irq, void *dev_id)
{
	struct sitronix_ts *ts = dev_id;
	int ret;

	if (ts->suspended)
		return IRQ_HANDLED;

	mutex_lock(&ts->lock);
	ret = sitronix_ts_report(ts);
	mutex_unlock(&ts->lock);

	return ret ? IRQ_NONE : IRQ_HANDLED;
}

static int sitronix_ts_input_init(struct sitronix_ts *ts)
{
	struct input_dev *input;
	int error;

	input = devm_input_allocate_device(&ts->client->dev);
	if (!input)
		return -ENOMEM;

	ts->input = input;

	input->name = "Sitronix I2C Touchscreen";
	input->id.bustype = BUS_I2C;

	input_set_capability(input, EV_KEY, BTN_TOUCH);
	__set_bit(EV_ABS, input->evbit);

	input_set_abs_params(input, ABS_X, 0, SITRONIX_TS_MAX_X, 0, 0);
	input_set_abs_params(input, ABS_Y, 0, SITRONIX_TS_MAX_Y, 0, 0);
	input_set_abs_params(input, ABS_MT_POSITION_X, 0, SITRONIX_TS_MAX_X, 0, 0);
	input_set_abs_params(input, ABS_MT_POSITION_Y, 0, SITRONIX_TS_MAX_Y, 0, 0);

	error = input_mt_init_slots(input, SITRONIX_TS_MAX_TOUCHES, INPUT_MT_DIRECT);
	if (error)
		return error;

	error = input_register_device(input);
	if (error)
		return error;

	return 0;
}

static int sitronix_ts_probe(struct i2c_client *client,
			       const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct sitronix_ts *ts;
	int irq_gpio, rst_gpio;
	unsigned long irq_flags = IRQF_ONESHOT;
	int error;

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
		return -ENODEV;

	ts = devm_kzalloc(dev, sizeof(*ts), GFP_KERNEL);
	if (!ts)
		return -ENOMEM;

	mutex_init(&ts->lock);
	ts->client = client;
	ts->suspended = false;

	irq_gpio = of_get_named_gpio_flags(dev->of_node, "irq-gpio", 0, &ts->irq_flags);
	rst_gpio = of_get_named_gpio_flags(dev->of_node, "rst-gpio", 0, &ts->rst_flags);

	if (gpio_is_valid(irq_gpio)) {
		error = devm_gpio_request_one(dev, irq_gpio, GPIOF_IN, "sitronix_irq");
		if (error)
			return error;
	} else {
		dev_err(dev, "invalid irq-gpio\n");
		return -EINVAL;
	}

	if (gpio_is_valid(rst_gpio)) {
		error = devm_gpio_request_one(dev, rst_gpio, GPIOF_OUT_INIT_HIGH,
					  "sitronix_rst");
		if (error)
			return error;
	}

	ts->irq_gpio = irq_gpio;
	ts->rst_gpio = rst_gpio;

	error = sitronix_ts_reset(ts);
	if (error)
		return error;

	error = sitronix_ts_input_init(ts);
	if (error) {
		dev_err(dev, "failed to init input device: %d\n", error);
		return error;
	}

	client->irq = gpiod_to_irq(devm_gpiod_get_index(dev, NULL, 0, GPIOD_IN));
	if (client->irq <= 0) {
		dev_warn(dev, "using GPIO interrupt mapping via irq-gpio\n");
		client->irq = gpio_to_irq(ts->irq_gpio);
	}

	if (client->irq <= 0) {
		dev_err(dev, "failed to get IRQ\n");
		return client->irq ?: -EINVAL;
	}

	irq_flags |= IRQF_TRIGGER_FALLING;

	error = devm_request_threaded_irq(dev, client->irq,
				   NULL, sitronix_ts_irq_thread,
				   irq_flags, SITRONIX_TS_I2C_DRVNAME, ts);
	if (error) {
		dev_err(dev, "failed to request IRQ: %d\n", error);
		return error;
	}

	i2c_set_clientdata(client, ts);

	dev_info(dev, "Sitronix I2C touchscreen probed at addr 0x%02x\n",
		 client->addr);

	return 0;
}

static int sitronix_ts_remove(struct i2c_client *client)
{
	struct sitronix_ts *ts = i2c_get_clientdata(client);

	ts->suspended = true;

	return 0;
}

#ifdef CONFIG_PM_SLEEP
static int sitronix_ts_suspend(struct device *dev)
{
	struct sitronix_ts *ts = dev_get_drvdata(dev);

	ts->suspended = true;
	if (ts->client->irq)
		disable_irq(ts->client->irq);

	return 0;
}

static int sitronix_ts_resume(struct device *dev)
{
	struct sitronix_ts *ts = dev_get_drvdata(dev);

	ts->suspended = false;
	if (ts->client->irq)
		enable_irq(ts->client->irq);

	return 0;
}

static const struct dev_pm_ops sitronix_ts_pm_ops = {
	.suspend = sitronix_ts_suspend,
	.resume  = sitronix_ts_resume,
};
#endif

static const struct of_device_id sitronix_ts_of_match[] = {
	{ .compatible = SITRONIX_TS_NAME },
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, sitronix_ts_of_match);

static const struct i2c_device_id sitronix_ts_id[] = {
	{ SITRONIX_TS_NAME, 0 },
	{ }
};
MODULE_DEVICE_TABLE(i2c, sitronix_ts_id);

static struct i2c_driver sitronix_ts_i2c_driver = {
	.driver = {
		.name  = SITRONIX_TS_I2C_DRVNAME,
#ifdef CONFIG_PM_SLEEP
		.pm    = &sitronix_ts_pm_ops,
#endif
		.of_match_table = sitronix_ts_of_match,
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

MODULE_AUTHOR("OpenCentauri/Perplexity Assistant");
MODULE_DESCRIPTION("Sitronix I2C touchscreen driver for 0x55 compatible with sitronixts DTS");
MODULE_LICENSE("GPL");
