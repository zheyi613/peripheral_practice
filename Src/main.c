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
	int16_t get = 0;
	float tmp = 0;
	usart3_default_init();
	i2c1_master_default_init();
	mpu6050_init();
	// i2c_transmit(I2C1, 0b1101010, 0x0F, 0b10100001, 1, &div);

	while (1) {
		// i2c_receive(I2C1, MPU6050_ADDRESS, MPU6050_TEMP_OUT, 2, &div_get);
		printf("t = %f\r\n", mpu6050_get_temperature());
		systick_delay_ms(500);
	}
	return 0;
}