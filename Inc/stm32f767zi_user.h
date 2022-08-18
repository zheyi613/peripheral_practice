/**
 * @file stm32f767zi_user.h
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief user define
 * @date 2022-08-09
 */

#ifndef __STM32F767ZI_USER_H
#define __STM32F767ZI_USER_H

#include "stm32f767zi_hal.h"
#include "stm32f767zi_gpio.h"

typedef uint32_t led_t;
typedef uint32_t button_t;

#define USER_LED_MODE           (1U << 0)
#define USER_BUTTON_MODE        0U                  // Button of GPIOC input mode (default)

#define USER_LED1_MODE          (1U << 0)           // LED1 of GPIOB output mode
#define USER_LED2_MODE          (1U << 14)          // LED2 of GPIOB output mode
#define USER_LED3_MODE          (1U << 28)          // LED3 of GPIOB output mode      

#define USER_LED1_POS           0
#define USER_LED2_POS           7
#define USER_LED3_POS           14

#define USER_LED1               (1U << USER_LED1_POS)           // LED1 (greed):  PIN0
#define USER_LED2               (1U << USER_LED2_POS)           // LED2 (blue):   PIN7
#define USER_LED3               (1U << USER_LED3_POS)           // LED3 (red):    PIN14

#define USER_BUTTON_POS         13
#define USER_BUTTON             (1U << USER_BUTTON_POS)         // Button:        PIN13

void led_init(void);
void button_init(void);
void led_toggle(led_t led);
void led_on(led_t led);
void led_off(led_t led);

#endif