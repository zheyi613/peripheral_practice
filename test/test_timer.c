/**
 * @file test_timer.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief main
 * @date 2022-08-16
 */

#include "stm32f767zi_hal.h"
#include "stm32f767zi_gpio.h"
#include "stm32f767zi_usart.h"
#include <stdio.h>

#define SYSTICK_LOAD_VAL        16000

#define TIM_CR1_CEN             1U
#define TIM_SR_UIF              1U

void systick_delay_ms(int delay);

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

void systick_delay_ms(int delay)
{
        // Reload the number of clocks per millisecond
        SYST->RVR = SYSTICK_LOAD_VAL;
        // Clear the current value register
        SYST->CVR = 0;
        // Select clock source and enable systick
        SYST->CSR = SYST_CSR_ENABLE | SYST_CSR_CLKSRC;

        for (int i = 0; i < delay; i++)
                while (!(SYST->CSR & SYST_CSR_COUNTFLAG));
        
        SYST->CSR = 0;
}

void tim1_1Hz_init(void)
{
        // Enable clock access to TIM1
        RCC->APB2ENR |= TIM1_CLK_EN;
        // Set the prescaler
        TIM1->PSC = 1600 - 1;   // 16000000 / 1600 = 10000
        // Set auto-reload value
        TIM1->ARR = 10000 - 1;
        // Enable timer
        TIM1->CR1 |= TIM_CR1_CEN;
}