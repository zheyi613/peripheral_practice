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
#include "stm32f767zi_timer.h"
#include "stm32f767zi_usart.h"
#include <stdbool.h>
#include <stdio.h>

bool flag_get = false;

int main(void)
{
	float get[3] = {0};
	float err[6] = {0};
	float state[3][2] = {0};

	fpu_enable();
	usart3_default_init();
	i2c1_master_default_init();
	tim1_interrupt_init(100);
	mpu6050_power_on();

	mpu6050_selftest(err);
	printf("Change from Factory Trim:\r\n");

	for (int i = 0; i < 6; i++) {
		printf("%.2f, ", err[i]);
	}

	printf("\r\n");
	mpu6050_init(100, 2, 250);

	while (1) {
		if (flag_get) {
			mpu6050_get_gyro(get);
			mpu6050_kalman_gyro(state, get);

			for (int i = 0; i < 3; i++) {
				printf("%.2f %.3f ", state[i][0], state[i][1]);
			}

			printf("\r\n");
			flag_get = false;
		}
	}

	return 0;
}

void TIM1_UP_TIM10_IRQHandler(void)
{
	// Check whether update interrupt is pending
	if ((TIM1->SR & TIM_SR_UIF) != 0) {
		// Clear the update interrupt flag
		TIM1->SR &= ~TIM_SR_UIF;
		// enable get data flag
		flag_get = true;
	}
}