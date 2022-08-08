/**
 * @file main.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief test usart code
 * @date 2022-08-01
 */

#include "peripheral_base.h"

int main(void) {

    // test LED1 2 3
    RCC_AHB1EN_REG |= GPIOB_CLK_EN;

    GPIO_MODE_REG |= USER_LED1_MODER | USER_LED2_MODER;

    GPIO_OD_REG |= USER_LED1 | USER_LED2;

    return 0;
}