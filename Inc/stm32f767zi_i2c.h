/**
 * @file stm32f767zi_i2c.h
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief Inter-intergrated circuit
 * @date 2022-08-20
 */

#ifndef __STM32F767ZI_I2C_H
#define __STM32F767ZI_I2C_H

#include "stm32f767zi_hal.h"
#include "stm32f767zi_gpio.h"
// Control register 1
#define I2C_CR1_PE              0U              // Peripheral enable
// Own address 1 register
#define I2C_OAR1_OA1            (0xFFU << 1)    // Interface address
#define I2C_OAR1_OA1MODE        (1U << 10)      // Own Address 1 10-bits mode

#define I2C_AF                  7U              // 0b0100
#define I2C2_SCL_POS            10              // PB10
#define I2C2_SDA_POS            11              // PB11

#define I2C2_EV_IRQn            33U             // I2C 2 event interrupt

#endif
