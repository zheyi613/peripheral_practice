/**
 * @file stm32f767zi_spi.c
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief Serial Peripheral interface
 * @date 2022-09-26
 */

#include "stm32f767zi_spi.h"

void spi1_master_cfg(void)
{
        // Enable the peripheral clock of GPIOB
        RCC->AHB1ENR |= GPIOA_CLK_EN;
        // Configure PA5(SCK) and PA7(MOSI) to alternative function 
        GPIOA->MODER |= GPIO_MODE_ALTFN << (SPI1_SCK_POS << 1);
        GPIOA->MODER |= GPIO_MODE_ALTFN << (SPI1_MOSI_POS << 1);
        // Select alternative function type as AF5
        GPIOA->AFR[SPI1_SCK_POS >> 3] |= SPI1_AF << ((SPI1_SCK_POS & 0x7U) << 2);
        GPIOA->AFR[SPI1_MOSI_POS >> 3] |= SPI1_AF << ((SPI1_MOSI_POS & 0x7U) << 2);
        // Set pin speed to very high
        GPIOA->OSPEEDR |= GPIO_OSPEEDER_VERY_HIGH << (SPI1_SCK_POS << 2);
        GPIOA->OSPEEDR |= GPIO_OSPEEDER_VERY_HIGH << (SPI1_MOSI_POS << 2);
        // Enable internnal pull-down
        GPIOA->PUPDR |= GPIO_PUPDR_PULL_DOWN << (SPI1_SCK_POS << 1);
        GPIOA->PUPDR |= GPIO_PUPDR_PULL_DOWN << (SPI1_MOSI_POS << 1);
        // SPI interrupt in the NVIC
        NVIC->ISER[(((uint32_t)SPI1_IRQn) >> 5UL)] =
		(uint32_t)(1UL << (((uint32_t)SPI1_IRQn) & 0x1FUL));
        // Configure SPI1 communication
        RCC->APB2ENR |= SPI1_CLK_EN;
        // Set clock to f_PCLK / 256
        SPI1->CR1 |= (7U << SPI_CR1_BR_POS);
        // Select Tx only
        SPI1->CR1 |= SPI_CR1_BIDIOE;
        // Select 1-line bidirectional data mode selected
        SPI1->CR1 |= SPI_CR1_BIDI_MODE;
        // Set CPOL to 1 and CPHA to 1
        SPI1->CR1 |= SPI_CR1_CPHA;
        SPI1->CR1 |= SPI_CR1_CPOL;
        // Set data width to 8 bits
        SPI1->CR2 |= (8U - 1) << SPI_CR2_DS_POS;
        // Enable software slave management
        SPI1->CR1 |= SPI_CR1_SSM;
        // Enable slave select output
        SPI1->CR2 |= SPI_CR2_SSOE;
	// Set fifo reception threshold
        SPI3->CR2 |= SPI_CR2_FRXTH;
        // Enable TXE interrupt
        SPI1->CR2 |= SPI_CR2_TXEIE;
        // Set mode to master
        SPI1->CR1 |= SPI_CR1_MSTR;
}

void spi3_slave_cfg(void)
{
        // Enable the peripheral clock of GPIOB
        RCC->AHB1ENR |= GPIOB_CLK_EN;
        // Configure PB3(SCK) and PB4(MISO) to alternative function 
        GPIOB->MODER |= GPIO_MODE_ALTFN << (SPI3_SCK_POS << 1);
        GPIOB->MODER |= GPIO_MODE_ALTFN << (SPI3_MISO_POS << 1);
        // Select alternative function type as AF5
        GPIOB->AFR[SPI3_SCK_POS >> 3] |= SPI3_AF << ((SPI3_SCK_POS & 0x7U) << 2);
        GPIOB->AFR[SPI3_MISO_POS >> 3] |= SPI3_AF << ((SPI3_MISO_POS & 0x7U) << 2);
        // Set pin speed to very high
        GPIOB->OSPEEDR |= GPIO_OSPEEDER_VERY_HIGH << (SPI3_SCK_POS << 2);
        GPIOB->OSPEEDR |= GPIO_OSPEEDER_VERY_HIGH << (SPI3_MISO_POS << 2);
        // Enable internnal pull-down
        GPIOB->PUPDR |= GPIO_PUPDR_PULL_DOWN << (SPI3_SCK_POS << 1);
        GPIOB->PUPDR |= GPIO_PUPDR_PULL_DOWN << (SPI3_MISO_POS << 1);
        // SPI interrupt in the NVIC
        NVIC->ISER[(((uint32_t)SPI3_IRQn) >> 5UL)] =
		(uint32_t)(1UL << (((uint32_t)SPI3_IRQn) & 0x1FUL));
        // Configure SPI3 communication
        RCC->APB1ENR |= SPI3_CLK_EN;
        // Set clock to f_PCLK / 256
        SPI3->CR1 |= (7U << SPI_CR1_BR_POS);
        // Select 1-line bidirectional data mode selected
        SPI3->CR1 |= SPI_CR1_BIDI_MODE;
        // Set CPOL to 1 and CPHA to 1
        SPI3->CR1 |= SPI_CR1_CPHA;
        SPI3->CR1 |= SPI_CR1_CPOL;
        // Set data width to 8 bits
        SPI3->CR2 |= (8U - 1) << SPI_CR2_DS_POS;
        // Enable software slave management
        SPI3->CR1 |= SPI_CR1_SSM;
	// Enable slave select output
        SPI1->CR2 |= SPI_CR2_SSOE;
        // Set fifo reception threshold
        SPI3->CR2 |= SPI_CR2_FRXTH;
        // Enable RXXE interrupt
        SPI3->CR2 |= SPI_CR2_RXNEIE;
}

void spi_en(SPI_reg_t *SPIx)
{
	SPIx->CR1 |= SPI_CR1_SPE;
}