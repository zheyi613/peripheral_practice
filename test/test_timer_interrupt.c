/**
 * @file test_timer_interrupt.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief test interrupt of timer
 * @date 2022-08-18
 */

#include "stm32f767zi_hal.h"
#include "stm32f767zi_gpio.h"
#include "stm32f767zi_usart.h"
#include "stm32f767zi_user.h"
#include "stm32f767zi_timer.h"
#include <stdio.h>

int main(void) {
        led_init();
        usart3_default_init();
        tim1_1Hz_interrupt_init();

        while (1) {

        }

        return 0;
}

void TIM1_UP_TIM10_IRQHandler(void)
{
        // Check whether update interrupt is pending
        if ((TIM1->SR & TIM_SR_UIF) != 0) {
                // Clear the update interrupt flag
                TIM1->SR &= ~TIM_SR_UIF;
                // toggle led2 and print message
                led_toggle(USER_LED1 | USER_LED2 | USER_LED3);
                printf("One second just passed!\r\n");
        }
}
