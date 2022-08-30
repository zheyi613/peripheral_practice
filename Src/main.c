/**
 * @file test_mpu6050.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief test i2c for mpu6050
 * @date 2022-08-26
 */

#include "mpu6050.h"
#include "stm32f767zi_gpio.h"
#include "stm32f767zi_hal.h"
#include "stm32f767zi_i2c.h"
#include "stm32f767zi_systick.h"
#include "stm32f767zi_usart.h"
#include <stdio.h>

int main(void)
{
	float get[7] = {0};
	float err[6] = {0};

	usart3_default_init();
	i2c1_master_default_init();
	mpu6050_power_on();

	mpu6050_selftest(err);
	printf("Change from Factory Trim: ");
	
	for (int i = 0; i < 6; i++) {
		printf("%.2f, ", err[i]);
	}

	printf("\r\n");
	mpu6050_init(20, 2, 250);

	while (1) {
		mpu6050_get_all(get);

		for (int i = 0; i < 7; i++)
			printf("d%d = %.2f ", i, get[i]);

		printf("\r\n");
		systick_delay_ms(100);
	}

	return 0;
}