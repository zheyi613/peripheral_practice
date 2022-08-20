/**
 * @file stm32f767zi_i2c.c
 * @author ufo880613@gmail.com (ufo880613@gmail.com)
 * @brief Inter-intergrated circuit
 * @date 2022-08-20
 */

#include "stm32f767zi_i2c.h"

void i2c2_slave_default_init(void)
{
        /* Configure SCL/SDA line */

        // Enable clock for GPIOB
        RCC->AHB1ENR |= GPIOB_CLK_EN;
        // Configure PB10(SCL) and PB11(SDA) mode to alternative function
        gpio_set_mode(GPIOB, I2C2_SCL_POS, GPIO_MODE_ALTFN);
        gpio_set_mode(GPIOB, I2C2_SDA_POS, GPIO_MODE_ALTFN);
        // Select alternate function type as AF4 (I2C2_SCL/I2C_SDA)
        MODIFY_REG(GPIOB->AFR[1], 0xFF00UL, (I2C_AF << 8) | (I2C_AF << 12));
        // Set pin output type to open-drain
        GPIOB->OTYPER |= GPIO_OTYPER_OPEN_DRAIN << I2C2_SCL_POS;
        GPIOB->OTYPER |= GPIO_OTYPER_OPEN_DRAIN << I2C2_SDA_POS;
        // Enable internal pull-up register
        GPIOB->PUPDR |= GPIO_PUPDR_PULL_UP << 20;
        GPIOB->PUPDR |= GPIO_PUPDR_PULL_UP << 22;
        
        /* Configure I2C parameters */

        // Enable clock access to the I2C module
        RCC->APB1ENR |= I2C2_CLK_EN;
        // Enable I2c interrupt in the NVIC
        NVIC->ISER[(((uint32_t)I2C2_EV_IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)I2C2_EV_IRQn) & 0x1FUL));
        // Disable I2C module
        I2C2->CR1 &= ~I2C_CR1_PE;
        // Set device address
        // Enable I2C module
        // Enable ADDR interrupt
        // Enable NACK interrupt
        // Enable STOP interrupt

}

static void i2c_set_ownAddress1(uint32_t ownAddress1, uint32_t ownAddrSize)
{
        MODIFY_REG(I2C->OAR1, I2C_OAR1_OA1 | I2C_OAR1_OA1MODE, ownAddress1 | ownAddrSize);
}