/**
 * @file test_usart.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief test usart
 * @date 2022-08-15
 */

#include "stm32f767zi_hal.h"
#include "stm32f767zi_gpio.h"
#include "stm32f767zi_usart.h"
#include "stm32f767zi_user.h"
#include <stdio.h>

int main(void) {
        int n = 0;
        char ch = '0';
        led_init();
        button_init();
        usart3_default_init();
        while (1) {
                printf("haha\n\rn = ");
                scanf("%d", &n);
                fflush(stdin);
                printf("%d\n\r",n);    
                for (int i = 0; i < n; i++) {
                        ch = usart_read(USART3);
                        printf("led%c toggle!\r\n", ch);
                        switch (ch)
                        {
                        case '1':
                                led_toggle(USER_LED1);
                                break;
                        case '2':
                                led_toggle(USER_LED2);
                                break;
                        case '3':
                                led_toggle(USER_LED3);
                                break;
                        default:
                                break;
                        }
                }
        }

        return 0;
}