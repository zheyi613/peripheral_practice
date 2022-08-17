/**
 * @file test_adc.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief test adc
 * @date 2022-08-16
 */

#include "stm32f767zi_hal.h"
#include "stm32f767zi_gpio.h"
#include "stm32f767zi_usart.h"
#include "stm32f767zi_adc.h"
#include <stdio.h>

int main(void) {
        usart3_default_init();
        pa4_adc1_init();
        
        while (1) {
                // Get analog signal from PA4
                adc1_start_conversion();
                printf("value = %ld\n\r", adc1_get_data());
                for (int i = 0; i < 1000000; i++);
        }

        return 0;
}