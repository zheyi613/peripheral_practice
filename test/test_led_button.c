/**
 * @file test_led_button.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief test led and button
 * @date 2022-08-09
 */

#include "stm32f767zi_hal.h"
#include "stm32f767zi_user.h"

void GPIO_mode(GPIO_reg_t *pGPIOx, uint32_t Pin, uint32_t Mode)
{
        pGPIOx->MODER = (pGPIOx->MODER & ~(0x03 << (Pin * 2))) | (Mode << (Pin * 2));
}

int main(void) {
        RCC->AHB1ENR |= GPIOB_CLK_EN | GPIOC_CLK_EN;

        GPIO_mode(GPIOB, USER_LED1_POS, USER_LED_MODE);
        GPIO_mode(GPIOB, USER_LED2_POS, USER_LED_MODE);
        GPIO_mode(GPIOB, USER_LED3_POS, USER_LED_MODE);
        GPIO_mode(GPIOC, USER_BUTTON_POS, USER_BUTTON_MODE);

        while (1) {
                /* toggle LED */
                // GPIOB->ODR ^= USER_LED1 | USER_LED2;
                // for (int i = 0; i < 500000; i++);
                /* if the user button is pressed, LEDs turn on. */
                if (GPIOC->IDR & USER_BUTTON) {
                        GPIOB->BSRR |= USER_LED1 | USER_LED2 | USER_LED3;
                }
                else {
                        GPIOB->BSRR |= (USER_LED1 | USER_LED2 | USER_LED3) << 16;
                }
        }

        return 0;
}