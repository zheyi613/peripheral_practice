/**
 * @file stm32f767zi_hal.h
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief stm32f767zi hardware abstract layer
 * @date 2022-08-10
 */

#ifndef __STM32F767ZI_HAL_H
#define __STM32F767ZI_HAL_H

#include <stdint.h>

#define __IO                    volatile

#define PERIPH_BASE             0x40000000UL        // base of 512-Mbyte Block 2 Peripherals
#define AHB1_OFFSET             0x00020000UL        // Advanced High Performance Bus
#define AHB1_BASE               (PERIPH_BASE + AHB1_OFFSET)
#define GPIOB_OFFSET            0x00000400UL        // General Purpose Input/Output B
#define GPIOB_BASE              (AHB1_BASE + GPIOB_OFFSET)
#define GPIOC_OFFSET            0x00000800UL        // General Purpose Input/Output C
#define GPIOC_BASE              (AHB1_BASE + GPIOC_OFFSET)
#define RCC_OFFSET              0x00003800UL        // Reset Clock Control
#define RCC_BASE                (AHB1_BASE + RCC_OFFSET)

#define GPIOB_CLK_EN            (1U << 1)           // GPIOB Clock at RCC AHB1EN PIN1
#define GPIOC_CLK_EN            (1U << 2)           // GPIOC Clock at RCC AHB1EN PIN2

typedef struct {
        __IO uint32_t MODER;                        // GPIO port mode register.                 Address offset: 0x00
        __IO uint32_t DUMMY[3];                     // GPIO port ... 
        __IO uint32_t IDR;                          // GPIO port input data register.           Address offset: 0x10
        __IO uint32_t ODR;                          // GPIO port output data register.          Address offset: 0x14
        __IO uint32_t BSRR;                         // GPIO port bit set/reset register.        Address offset: 0x18
} GPIO_reg_t;

typedef struct {
        __IO uint32_t DUMMY[12];                    // RCC ...
        __IO uint32_t AHB1ENR;                      // RCC AHB1 peripheral clock register.      Address offset: 0x30
} RCC_reg_t;

#define GPIOB           ((GPIO_reg_t *)GPIOB_BASE)
#define GPIOC           ((GPIO_reg_t *)GPIOC_BASE)
#define RCC             ((RCC_reg_t *)RCC_BASE)

#endif