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

#define WRITE_REG(REG, VAL)             REG = VAL
#define MODIFY_REG(REG, MASK, VAL)      WRITE_REG(REG, (REG & ~(MASK)) | (VAL))

#define PERIPH_CLK              16000000UL                      // Frequency of peripheral (16MHz)
#define PERIPH_BASE             0x40000000UL                    // Base of 512-Mbyte Block 2 Peripherals 
#define AHB1_BASE               (PERIPH_BASE + 0x00020000UL)    // Advanced High Performance Bus

#define GPIOA_BASE              (AHB1_BASE + 0x00000000UL)      // Gereral Purpose Input/Output A
#define GPIOB_BASE              (AHB1_BASE + 0x00000400UL)      // Gereral Purpose Input/Output B
#define GPIOC_BASE              (AHB1_BASE + 0x00000800UL)      // Gereral Purpose Input/Output C
#define GPIOD_BASE              (AHB1_BASE + 0x00000C00UL)      // Gereral Purpose Input/Output D
       
#define RCC_BASE                (AHB1_BASE + 0x00003800UL)      // Reset Clock Control

#define APB1_BASE               PERIPH_BASE

#define USART3_BASE             (APB1_BASE + 0x00004800UL)      // USART 3

#define GPIOB_CLK_EN            (1U << 1)           // Enable GPIOB clock at RCC AHB1EN PIN1
#define GPIOC_CLK_EN            (1U << 2)           // Enable GPIOC clock at RCC AHB1EN PIN2
#define GPIOD_CLK_EN            (1U << 3)           // Enable GPIOD clock at RCC AHB1EN PIN3

#define USART3_CLK_EN            (1U << 18)         // Enable USART3 clock at RCC APB1EN PIN18

typedef struct {
        __IO uint32_t MODER;            // GPIO port mode register                              Address offset: 0x00
        __IO uint32_t DUMMY[3];         // GPIO port ... 
        __IO uint32_t IDR;              // GPIO port input data register                        Address offset: 0x10
        __IO uint32_t ODR;              // GPIO port output data register                       Address offset: 0x14
        __IO uint32_t BSRR;             // GPIO port bit set/reset register                     Address offset: 0x18
        __IO uint32_t LCKR;             // GPIO port configuration lock register                Address offset: 0x1C
        __IO uint32_t AFR[2];           // AFR[0]: GPIO alternate function low register         Address offset: 0x20
                                        // AFR[1]: GPIO alternate function high register        Address offset: 0x24
} GPIO_reg_t;

typedef struct {
        __IO uint32_t DUMMY[12];        // RCC ...
        __IO uint32_t AHB1ENR;          // RCC AHB1 peripheral clock register                   Address offset: 0x30
        __IO uint32_t DUMMY2[3];        // RCC ...
        __IO uint32_t APB1ENR;          // RCC APB1 peripheral clock enable register            Address offset: 0x40
} RCC_reg_t;

typedef struct {
        __IO uint32_t CR1;              // Control register 1                                   Address offset: 0x00
        __IO uint32_t CR2;              // Control register 2                                   Address offset: 0x04
        __IO uint32_t CR3;              // Control register 3                                   Address offset: 0x08
        __IO uint32_t BRR;              // Baud rate register                                   Address offset: 0x0C
        __IO uint32_t GTPR;             // Guard time and prescaler register                    Address offset: 0x10
        __IO uint32_t RTOR;             // Receiver timeout register                            Address offset: 0x14
        __IO uint32_t RQR;              // Request register                                     Address offset: 0x18
        __IO uint32_t ISR;              // Interrupt and status register                        Address offset: 0x1C
        __IO uint32_t ICR;              // Interrupt flag clear register                        Address offset: 0x20
        __IO uint32_t RDR;              // Receive data register                                Address offset: 0x24
        __IO uint32_t TDR;              // Transmit data register                               Address offset: 0x28
} USART_reg_t;

#define GPIOB           ((GPIO_reg_t *)GPIOB_BASE)
#define GPIOC           ((GPIO_reg_t *)GPIOC_BASE)
#define GPIOD           ((GPIO_reg_t *)GPIOD_BASE)
#define RCC             ((RCC_reg_t *)RCC_BASE)
#define USART3          ((USART_reg_t *)USART3_BASE)

#endif