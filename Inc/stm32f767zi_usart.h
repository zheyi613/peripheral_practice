/**
 * @file stm32f767zi_usart.h
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief usart/uart
 * @date 2022-08-10
 */

#ifndef __STM32F767ZI_USART_H
#define __STM32F767ZI_USART_H

#include "stm32f767zi_hal.h"
#include "stm32f767zi_gpio.h"

// Control register 1
#define USART_UE_MASK           (1U << 0)
#define USART_RE_POS            2
#define USART_RE_MASK           (1U << USART_RE_POS)
#define USART_TE_POS            3
#define USART_TE_MASK           (1U << USART_TE_POS)
#define USART_PS_POS            9
#define USART_PS_MASK           (1U << USART_PS_POS)
#define USART_PCE_POS           10
#define USART_PCE_MASK          (1U << USART_PCE_POS)
#define USART_M0_POS            12
#define USART_M0_MASK           (1U << USART_M0_POS)
#define USART_M1_POS            28
#define USART_M1_MASK           (1U << USART_M1_POS)
// Control register 2
#define USART_STOP_POS          12
#define USART_STOP_MASK         (3U << USART_STOP_POS)
// word length
#define USART_WORDLEN_7         7
#define USART_WORDLEN_8         8
#define USART_WORDLEN_9         9
// stop bits
#define USART_STOPBITS_1        0
#define USART_STOPBITS_0_5      1
#define USART_STOPBITS_2        2
#define USART_STOPBITS_1_5      3

#define USART3_AF               7U
#define USART3_TX_PIN           8U              // PD8
#define USART3_RX_PIN           9U              // PD9

void usart3_default_init(void);
void usart_write(USART_reg_t *USARTx, uint8_t value);
uint8_t usart_read(USART_reg_t *USARTx);

#endif