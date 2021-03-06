/*< DTS2012052303745 zhongjinrong 20120523 begin */
/*
 * leds-msm-pmic.c - MSM PMIC LEDs driver.
 *
 * Copyright (c) 2009, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/leds.h>
#include <mach/pmic.h>
#include <linux/module.h>

#ifdef CONFIG_HUAWEI_LEDS_PMIC
#include <linux/mfd/pmic8058.h>
#include <mach/gpio.h>
#include <mach/vreg.h>
#include <linux/gpio.h>
#include <linux/pwm.h>
#include <mach/pmic.h>


#include <linux/hardware_self_adapt.h>
#include <asm/mach-types.h>
#endif

#define LED_PWM_PERIOD ( NSEC_PER_SEC / ( 22 * 1000 ) )	/* ns, period of 22Khz */
#define LED_PWM_LEVEL 255
#define LED_PWM_DUTY_LEVEL (LED_PWM_PERIOD / LED_PWM_LEVEL)
#define LED_PM_GPIO25_PWM_ID  1
#define LED_ADD_VALUE			4
#define LED_PWM_LEVEL_ADJUST	226
#define LED_BL_MIN_LEVEL 	    30

#define LED_BRIGHTNESS_LEVEL  100
#define LED_BRIGHTNESS_OFF    0


/*< DTS2012022305689 qitongliang 20120223 begin */
static void msm_keypad_bl_led_set(struct led_classdev *led_cdev,
	enum led_brightness value)
{
/*delete some lines*/
	int ret = 0 ;
	if(LED_BRIGHTNESS_OFF >= value || LED_BRIGHTNESS_LEVEL < value )
	{
		   ret = pmic_set_keyled_intensity(LED_KEYPAD,LED_BRIGHTNESS_OFF  );
	}
	else
	{
		   ret = pmic_set_keyled_intensity(LED_KEYPAD, value);
	}
	if (ret)
		dev_err(led_cdev->dev, "can't set keypad backlight\n");
/*delete some lines*/
}
/* DTS2012022305689 qitongliang 20120223 end >*/

static struct led_classdev msm_kp_bl_led = {
/* delete some lines */
	.name			= "keyboard-backlight",
	.brightness_set		= msm_keypad_bl_led_set,
	.brightness		= LED_OFF,
};


static int msm_pmic_led_probe(struct platform_device *pdev)
{
	int rc;
	if(!machine_is_msm8255_u8730())
	{
		return 0;
	}
	rc = led_classdev_register(&pdev->dev, &msm_kp_bl_led);
	if (rc) {
		dev_err(&pdev->dev, "unable to register led class driver\n");
		return rc;
	}

  /*  delete some lines >*/

	msm_keypad_bl_led_set(&msm_kp_bl_led, LED_OFF);
	return rc;
}

static int __devexit msm_pmic_led_remove(struct platform_device *pdev)
{
	if(!machine_is_msm8255_u8730())
	{
		return 0;
	}
	led_classdev_unregister(&msm_kp_bl_led);

	return 0;
}

#ifdef CONFIG_PM
static int msm_pmic_led_suspend(struct platform_device *dev,
		pm_message_t state)
{
	led_classdev_suspend(&msm_kp_bl_led);

	return 0;
}

static int msm_pmic_led_resume(struct platform_device *dev)
{
	led_classdev_resume(&msm_kp_bl_led);

	return 0;
}
#else
#define msm_pmic_led_suspend NULL
#define msm_pmic_led_resume NULL
#endif

static struct platform_driver msm_pmic_led_driver = {
	.probe		= msm_pmic_led_probe,
	.remove		= __devexit_p(msm_pmic_led_remove),
	.suspend	= msm_pmic_led_suspend,
	.resume		= msm_pmic_led_resume,
	.driver		= {
		.name	= "pmic-keyboard-leds",
		.owner	= THIS_MODULE,
	},
};

static int __init msm_pmic_led_init(void)
{
	return platform_driver_register(&msm_pmic_led_driver);
}
module_init(msm_pmic_led_init);

static void __exit msm_pmic_led_exit(void)
{
	platform_driver_unregister(&msm_pmic_led_driver);
}
module_exit(msm_pmic_led_exit);

MODULE_DESCRIPTION("MSM PMIC LEDs driver");
MODULE_LICENSE("GPL v2");
MODULE_ALIAS("platform:pmic-leds");
/* DTS2012052303745 zhongjinrong 20120523 end >*/
