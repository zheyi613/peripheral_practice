/**
 * @file stm32f767zi_gpio.h
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief GPIO
 * @date 2022-08-10
 */

#ifndef __STM32F767ZI_GPIO_H
#define __STM32F767ZI_GPIO_H

#include "stm32f767zi_hal.h"

#define GPIO_MODE_INPUT         0U
#define GPIO_MODE_OUTPUT        1U
#define GPIO_MODE_ALTFN         2U
#define GPIO_MODE_ANALOG        3U

#define GPIO_OTYPER_PUSH_PULL   0U
#define GPIO_OTYPER_OPEN_DRAIN  1U

#define GPIO_PUPDR_NO           0U
#define GPIO_PUPDR_PULL_UP      1U
#define GPIO_PUPDR_PULL_DOWN    2U

void gpio_set_mode(GPIO_reg_t *GPIOx, uint32_t position, uint32_t mode);

#endif