// SPDX-License-Identifier: GPL-3.0 
// Copyright (C) 2020 Momoko Hara and Ryuichi Ueda. All right reserved.


#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include <linux/delay.h>


MODULE_AUTHOR("Momoko Hara and Ryuichi Ueda");
MODULE_DESCRIPTION("driver for LED control");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.1");
static dev_t dev;
static struct cdev cdv;
static struct class *cls = NULL;
static volatile u32 *gpio_base = NULL;

static ssize_t led_write(struct file* filp, const char* buf, size_t count, loff_t* pos)
{
	char c;
	int i;
	if(copy_from_user(&c, buf, sizeof(char)))
		return -EFAULT;
	
	if(c == '2')
	{
		for(i = 0; i < 10; i++)
       		{
			gpio_base[7] = 1 << 25;
			ssleep(1);

			gpio_base[10] = 1 << 25;
			ssleep(1);
		}
		
	}

	else if(c == '1')
		gpio_base[7] = 1 << 25;
	
	else if(c == '0') 
		gpio_base[10] = 1 << 25;
	

return 1; 
}

static ssize_t sushi_read(struct file* filp, char* buf, size_t count, loff_t* pos)
{
