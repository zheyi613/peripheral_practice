/**
 * @file test_adc_interrupt.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief test interrupt of adc
 * @date 2022-08-18
 */

#include "stm32f767zi_adc.h"
#include "stm32f767zi_gpio.h"
#include "stm32f767zi_hal.h"
#include "stm32f767zi_usart.h"
#include <stdio.h>

int main(void)
{
	usart3_default_init();
	pa4_adc1_interrupt_init();
	adc1_start_conversion();
	while (1) {
	}

	return 0;
}

void ADC_IRQHandler(void)
{
	// Check if end-of-conversion interrupt occured
	if ((ADC1->SR & ADC_SR_EOC) == ADC_SR_EOC) {
		// Clear EOC flag
		ADC1->SR &= ~ADC_SR_EOC;
		printf("value = %ld\n\r", ADC1->DR);
	}
}