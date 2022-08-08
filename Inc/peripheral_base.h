/**
 * @file peripheral_base.h
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief peripheral base
 * @date 2022-08-08
 */
#ifndef __PERIPHERAL_BASE_H
#define __PERIPHERAL_BASE_H

#define PERIPH_BASE             0x40000000UL    // base of 512-Mbyte Block 2 Peripherals

#define AHB1_OFFSET             0x00020000UL    // Advanced High Performance Bus
#define AHB1_BASE               PERIPH_BASE + AHB1_OFFSET

#define GPIOB_OFFSET            0x00000400UL    // General Purpose Input/Output
#define GPIOB_BASE              AHB1_BASE + GPIOB_OFFSET
#define GPIO_MODER_OFFSET       0x00000000UL    // GPIO Moder
#define GPIO_MODE_REG           (*(volatile unsigned int *)(GPIOB_BASE + GPIO_MODER_OFFSET))
#define GPIO_ODR_OFFSET         0x00000014UL    // GPIO output data register
#define GPIO_OD_REG             (*(volatile unsigned int *)(GPIOB_BASE + GPIO_ODR_OFFSET))

#define RCC_OFFSET              0x00003800UL    // Reset Clock Control
#define RCC_BASE                AHB1_BASE + RCC_OFFSET
#define RCC_AHB1EN_REG_OFFSET   0x00000030UL    // RCC AHB1 peripheral clock register (RCC_AHB1ENR)
#define RCC_AHB1EN_REG          (*(volatile unsigned int *)(RCC_BASE + RCC_AHB1EN_REG_OFFSET))

#define GPIOB_CLK_EN            (1U << 1)       // GPIOB Clock at RCC AHB1EN PIN1

#define USER_LED1_MODER         (1UL << 0)      // LED1 of GPIOB output mode
#define USER_LED2_MODER         (1UL << 14)     // LED2 of GPIOB output mode
#define USER_LED3_MODER         (1UL << 28)     // LED3 of GPIOB output mode

#define USER_LED1               (1UL << 0)      // LED1 (greed):  PIN0
#define USER_LED2               (1UL << 7)      // LED2 (blue):   PIN7
#define USER_LED3               (1UL << 14)     // LED3 (red):    PIN14

#endif