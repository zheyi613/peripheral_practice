/**
 * @file test_timer.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief test systick and timer
 * @date 2022-08-16
 */

#include "stm32f767zi_hal.h"
#include "stm32f767zi_gpio.h"
#include "stm32f767zi_usart.h"
#include "stm32f767zi_systick.h"
#include "stm32f767zi_timer.h"
#include <stdio.h>

int main(void) {
        usart3_default_init();

        printf("Wait one second passed!\n\r");
        systick_delay_ms(1000);

        printf("timer start!!\n\r");
        tim1_1Hz_init();

        while (1) {
                // Wait for update interrupt flag
                while (!(TIM1->SR & TIM_SR_UIF));
                // Clear UIF
                TIM1->SR &= ~TIM_SR_UIF;
                printf("One second just passed!\n\r");
        }

        return 0;
}
