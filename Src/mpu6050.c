/**
 * @file mpu6050.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief MPU6050 library for stm32f767zi
 * @date 2022-08-24
 */

#include "mpu6050.h"

void mpu6050_init(void)
{
	// P2 setting
	RCC->AHB1ENR |= GPIOG_CLK_EN;
	GPIOG->MODER |= GPIO_MODE_OUTPUT << 4;
	GPIOG->BSRR |= (1U << 2);
	systick_delay_ms(100);
	// Wake up
	uint8_t tmp = 0;
	i2c_transmit(I2C1, MPU6050_ADDRESS, MPU6050_PWR_MGMT_1, 1, &tmp);
}
/*
 * Temperature in degree C = (TEMP_OUT register value as a signed quantity) / 340 + 36.53
 */
float mpu6050_get_temperature(void)
{
	int16_t tmp = 0;
	i2c_receive(I2C1, MPU6050_ADDRESS, MPU6050_TEMP_OUT, 2, (uint8_t *)&tmp);
        return (float)tmp / 340.0F + 36.53F;
}
