/**
 * @file test_i2c.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief test i2c interface by self
 * @date 2022-08-23
 */

#include "stm32f767zi_gpio.h"
#include "stm32f767zi_hal.h"
#include "stm32f767zi_i2c.h"
#include "stm32f767zi_usart.h"
#include <stdio.h>

/*
 * Connect I2C2_SCL (PB10) to I2C1_SCL (PB6).
 * Connect I2C2_SDA (PB11) to I2C1_SDA (PB9).
 */

// Buffer used for transmission
const uint8_t msg[] = "HELLO";
uint8_t *p_tx_buff = (uint8_t *)msg;
uint8_t tx_size = sizeof(msg);
volatile uint8_t tx_index = 0;

// Buffer used for reception
uint8_t rx_buff[sizeof(msg)];
uint8_t rx_size = sizeof(msg);
volatile uint8_t rx_index = 0;

static void handle_i2c_master(void);

int main(void)
{
	usart3_default_init();
	i2c1_master_default_init();
	i2c2_slave_default_init();
	handle_i2c_master();

	while (1) {
	}

	return 0;
}

static void handle_i2c_master(void)
{
	// Set slave address
	I2C1->CR2 |= I2C_SLAVE_OWN_ADDRESS << 1;
	// 7-bits address mode
	I2C1->CR2 &= ~I2C_CR2_ADD10;
	// Set transfer size
	I2C1->CR2 |= (tx_size << I2C_CR2_NBYTES_POS);
	// Set automatic end mode
	I2C1->CR2 |= I2C_CR2_AUTOEND;
	// Generate start condition
	I2C1->CR2 |= I2C_CR2_START;
	// Loop until STOP flag is raised
	while (!(I2C1->ISR & I2C_ISR_STOPF)) {
		// check TXIS flag value in ISR register
		if (I2C1->ISR & I2C_ISR_TXIS) {
			// Write data in transmmit data register.
			// TXIS flag is cleared by writing data in TXDR register
			I2C1->TXDR = (*p_tx_buff++);
		}
	}
	// Clear stop flag
	I2C1->ICR |= I2C_ICR_STOPCF;
}

void I2C2_EV_IRQHandler(void)
{
	// Check ADDR flag value in ISR register
	if (I2C2->ISR & I2C_ISR_ADDR) {
		// Verify the address match with the own slave address
		if (i2c_get_address_matchcode(I2C2) == I2C_SLAVE_OWN_ADDRESS) {
			// Clear ADDR flag value in ISR register
			I2C2->ICR |= I2C_ICR_ADDRCF;
			// Enable receive interrupt
			I2C2->CR1 |= I2C_CR1_RXIE;
		}
	} else if (I2C2->ISR & I2C_ISR_RXNE) {
		rx_buff[rx_index++] = (I2C2->RXDR & 0xFF);
	} else if (I2C2->ISR & I2C_ISR_STOPF) {
		I2C2->ICR |= I2C_ICR_STOPCF;
		printf("Transmission complete...\n\r");
	}
}