/**
 * @file test_usart_interrupt.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief test interrupt of usart
 * @date 2022-08-18
 */

#include "stm32f767zi_hal.h"
#include "stm32f767zi_gpio.h"
#include "stm32f767zi_usart.h"
#include "stm32f767zi_user.h"

char ch;

int main(void) {
        led_init();
        usart3_interrupt_default_init();

        while (1) {
                switch (ch)
                {
                case '0':
                        led_off(USER_LED1 | USER_LED2 | USER_LED3);
                        break;
                case '1':
                        led_on(USER_LED1);
                        break;
                case '2':
                        led_on(USER_LED2);
                        break;
                case '3':
                        led_on(USER_LED3);
                        break;
                default:
                        break;
                }
        }

        return 0;
}

void USART3_IRQHandler(void)
{
        if ((USART3->ISR & USART_ISR_TXE) == USART_ISR_TXE)
        {
                // transmit a ASCII code
                USART3->TDR = 'R';
        }
        if ((USART3->ISR & USART_ISR_RXNE) == USART_ISR_RXNE)
        {
                // receive a ASCII code
                ch = USART3->RDR & 0xFFU;
        }
}