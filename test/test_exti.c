/**
 * @file test_exti.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief test extended interrupt with button (PC13)
 * @date 2022-08-17
 */

#include "stm32f767zi_gpio.h"
#include "stm32f767zi_hal.h"
#include "stm32f767zi_usart.h"
#include "stm32f767zi_user.h"
#include <stdio.h>

#define EXTI15_10_IRQn 40U

void pc13_exti_init(void);

int main(void)
{
	usart3_default_init();
	pc13_exti_init();

	while (1) {
	}

	return 0;
}

void pc13_exti_init(void)
{
	// Enable clock access to PORTC
	RCC->AHB1ENR |= GPIOC_CLK_EN;
	// Set PC13 to input
	gpio_set_mode(GPIOC, USER_BUTTON_POS, USER_BUTTON_MODE);
	// Enable clock access to SYSCFG module
	RCC->APB2ENR |= SYSCFG_CLK_EN;
	// Clear port selection for EXTI13
	SYSCFG->EXTICR[3] &= ~(0xFU << 4);
	// Select PORTC for EXTI13
	SYSCFG->EXTICR[3] |= 1U << 5;
	// Unmask EXTI13
	EXTI->IMR |= USER_BUTTON;
	// Select falling edge trigger
	EXTI->FTSR |= USER_BUTTON;
	// Enable EXTI13 in NVIC
	NVIC->ISER[(((uint32_t)EXTI15_10_IRQn) >> 5UL)] =
		(uint32_t)(1UL << (((uint32_t)EXTI15_10_IRQn) & 0x1FUL));
}

void EXTI15_10_IRQHandler(void)
{
	if ((EXTI->PR & USER_BUTTON) != 0) {
		// Clear PR flag
		EXTI->PR |= USER_BUTTON;
		// Print message
		printf("Button pressed...\n\r");
	}
}