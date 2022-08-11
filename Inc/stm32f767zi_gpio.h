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

void gpio_set_mode(GPIO_reg_t *GPIOx, uint32_t pin, uint32_t mode);

#endif