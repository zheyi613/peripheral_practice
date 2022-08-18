/**
 * @file test_systick_interrupt.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief test interrupt of system tick
 * @date 2022-08-18
 */

#include "stm32f767zi_hal.h"
#include "stm32f767zi_usart.h"
#include "stm32f767zi_systick.h"
#include <stdio.h>

int main(void) {
        usart3_default_init();
        systick_1hz_interrupt();

        while (1) {

        }

        return 0;
}

void SysTick_Handler(void)
{
        // print message
        printf("One second just passed!\n\r");
}