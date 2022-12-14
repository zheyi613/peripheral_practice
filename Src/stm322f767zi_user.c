/**
 * @file stm322f767zi_user.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief led and button function
 * @date 2022-08-11
 */

#include "stm32f767zi_user.h"

void led_init(void)
{
        RCC->AHB1ENR |= GPIOB_CLK_EN;
        gpio_set_mode(GPIOB, USER_LED1_POS, USER_LED_MODE);
        gpio_set_mode(GPIOB, USER_LED2_POS, USER_LED_MODE);
        gpio_set_mode(GPIOB, USER_LED3_POS, USER_LED_MODE);
}

void button_init(void)
{
        RCC->AHB1ENR |= GPIOC_CLK_EN;
        gpio_set_mode(GPIOC, USER_BUTTON_POS, USER_BUTTON_MODE);
}

void led_toggle(led_t led)
{
        GPIOB->ODR ^= led;
}

void led_on(led_t led)
{
        GPIOB->BSRR |= led;
}

void led_off(led_t led)
{
        GPIOB->BSRR |= led << 16;
}