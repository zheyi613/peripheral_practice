/**
 * @file test_spi.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief test spi
 * @date 2022-09-26
 */

#include "stm32f767zi_gpio.h"
#include "stm32f767zi_hal.h"
#include "stm32f767zi_spi.h"

uint8_t tx_buff[] = "Hello from SPI";
uint8_t tx_size = sizeof(tx_buff);
volatile uint8_t tx_idx = 0;

uint8_t rx_buff[sizeof(tx_buff)];
uint8_t rx_size = sizeof(rx_buff);
volatile uint8_t rx_idx = 0;

volatile uint8_t *spidr = (volatile uint8_t *) &SPI1->DR;

int main(void)
{
	spi1_master_cfg();
	spi3_slave_cfg();
	// slave receive must be first enable, 
	spi_en(SPI3);
	spi_en(SPI1);

	while (1) {

	}

	return 0;
}

void SPI1_IRQHandler(void)
{
	// Check TXE flag value in SR register
	if (SPI1->SR & SPI_SR_TXE)
		if (tx_idx < tx_size)
			*spidr = tx_buff[tx_idx++];
}

void SPI3_IRQHandler(void)
{
	// Check RXNE flag value in SR register
	if ((SPI3->SR & SPI_SR_RXNE))
		rx_buff[rx_idx++] = SPI3->DR;
}