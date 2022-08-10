/**
 * @file stm32f767zi_user.h
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief user define
 * @date 2022-08-09
 */

#ifndef __STM32F767ZI_USER_H
#define __STM32F767ZI_USER_H

#define USER_LED_MODE           (1U << 0)
#define USER_BUTTON_MODE        0U                  // Button of GPIOC input mode (default)

#define USER_LED1_MODE          (1U << 0)           // LED1 of GPIOB output mode
#define USER_LED2_MODE          (1U << 14)          // LED2 of GPIOB output mode
#define USER_LED3_MODE          (1U << 28)          // LED3 of GPIOB output mode      

#define USER_LED1_PIN           0
#define USER_LED2_PIN           7
#define USER_LED3_PIN           14

#define USER_LED1               (1U << USER_LED1_PIN)           // LED1 (greed):  PIN0
#define USER_LED2               (1U << USER_LED2_PIN)           // LED2 (blue):   PIN7
#define USER_LED3               (1U << USER_LED3_PIN)          // LED3 (red):    PIN14

#define USER_BUTTON_PIN         13
#define USER_BUTTON             (1U << 13)          // Button:        PIN13

#endif