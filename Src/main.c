/**
 * @file main.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief test usart code
 * @date 2022-08-01
 */

#include "stm32f767zi_hal.h"
#include "stm32f767zi_user.h"

int main(void) {
    RCC->AHB1ENR |= GPIOB_CLK_EN;

    GPIOB->MODER |= USER_LED1_MODE | USER_LED2_MODE;
    GPIOC->MODER |= USER_BUTTON_MODE;

    while (1)
    {
        // toggle LED
        GPIOB->ODR ^= USER_LED1 | USER_LED2;
        for (int i = 0; i < 500000; i++);
    }

    return 0;
}