/**
 * @file stm32f767zi_usart.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief usart/uart
 * @date 2022-08-10
 */

#include "stm32f767zi_usart.h"

void usart2_default_init(void)
{
        // Enable clock access to GPIOD.
        RCC->AHB1ENR |= GPIOD_CLK_EN;
        // Set PD5 (Tx) mode to alternate function.
        gpio_set_mode(GPIOD, USART2_TX_POS, GPIO_MODE_ALTFN);
        // Set PD6 (Rx) mode to alternate function.
        gpio_set_mode(GPIOD, USART2_RX_POS, GPIO_MODE_ALTFN);
        // Set alternate function to USART. GPIO_AFRH = AF7(0b0111) << 0 | AF7 << 4
        MODIFY_REG(GPIOD->AFR[0], 0xFFU, (USART3_AF << 20) | (USART3_AF << 24));
        // Enable clock to USART3 module
        RCC->APB1ENR |= USART2_CLK_EN;
        // Configure USART parameters (TE, RE, PS, PCE, M, STOP)
        MODIFY_REG(USART2->CR1, USART_CR1_TE_MASK | USART_CR1_RE_MASK, (1 << USART_CR1_TE_POS) | (1 << USART_CR1_RE_POS));
        // Set baud rate
        USART2->BRR = (PERIPH_CLK + (115200 / 2U)) / 115200;
        // enable USART3
        MODIFY_REG(USART2->CR1, USART_CR1_UE_MASK, 1);
}

// word length: 8
// transmit enable: enable
// parity: none
// stop bits: 1
// baud rate: 115200
void usart3_default_init(void)
{
        // Enable clock access to GPIOD.
        RCC->AHB1ENR |= GPIOD_CLK_EN;
        // Set PD8 (Tx) mode to alternate function.
        gpio_set_mode(GPIOD, USART3_TX_POS, GPIO_MODE_ALTFN);
        // Set PD9 (Rx) mode to alternate function.
        gpio_set_mode(GPIOD, USART3_RX_POS, GPIO_MODE_ALTFN);
        // Set alternate function to USART. GPIO_AFRH = AF7(0b0111) << 0 | AF7 << 4
        MODIFY_REG(GPIOD->AFR[1], 0xFFU, USART3_AF | (USART3_AF << 4));
        // Enable clock to USART3 module
        RCC->APB1ENR |= USART3_CLK_EN;
        // Configure USART parameters (TE, RE, PS, PCE, M, STOP)
        MODIFY_REG(USART3->CR1, USART_CR1_TE_MASK | USART_CR1_RE_MASK, (1 << USART_CR1_TE_POS) | (1 << USART_CR1_RE_POS));
        // Set baud rate
        USART3->BRR = (PERIPH_CLK + (115200 / 2U)) / 115200;
        // enable USART3
        MODIFY_REG(USART3->CR1, USART_CR1_UE_MASK, 1);
}

void usart_write(USART_reg_t *USARTx,uint8_t value)
{
        // Make sure transmit data register is empty
        while (!(USARTx->ISR & (1U << 7)));
        // Write value into transmit data register
        USARTx->TDR = value;
}

uint8_t usart_read(USART_reg_t *USARTx)
{
        while (!(USARTx->ISR & (1U << 5)));
        return USARTx->RDR & 0xFFU;
}

int __io_putchar(int ch)
{
        usart_write(USART3, ch);
        return ch;
}

int __io_getchar(void)
{
        return usart_read(USART3);
}