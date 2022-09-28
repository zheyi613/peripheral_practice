/**
 * @file stm32f767zi_spi.h
 * @author zheyi613 (zheyi880613@gmail.com)
 * @brief Serial Peripheral Interface
 * @date 2022-09-26
 */

#ifndef __STM32F767ZI_SPI_H
#define __STM32F767ZI_SPI_H

#include "stm32f767zi_hal.h"
#include "stm32f767zi_gpio.h"
// Control register 1
#define SPI_CR1_CPHA            1U
#define SPI_CR1_CPOL            (1U << 1)
#define SPI_CR1_MSTR            (1U << 2)
#define SPI_CR1_BR_POS          3
#define SPI_CR1_SPE             (1U << 6)
#define SPI_CR1_LSB_1ST         (1U << 7)
#define SPI_CR1_SSI             (1U << 8)
#define SPI_CR1_SSM             (1U << 9)
#define SPI_CR1_RX_ONLY         (1U << 10)
#define SPI_CR1_CRCL            (1U << 11)
#define SPI_CR1_CRC_NEXT        (1U << 12)
#define SPI_CR1_CRC_EN          (1U << 13)
#define SPI_CR1_BIDIOE          (1U << 14)
#define SPI_CR1_BIDI_MODE       (1U << 15)
// Control register 2
#define SPI_CR2_RXDMAEN         1U
#define SPI_CR2_TXDMAEN         (1U << 1)
#define SPI_CR2_SSOE            (1U << 2)
#define SPI_CR2_NSSP            (1U << 3)
#define SPI_CR2_FRF             (1U << 4)
#define SPI_CR2_ERRIE           (1U << 5)
#define SPI_CR2_RXNEIE          (1U << 6)
#define SPI_CR2_TXEIE           (1U << 7)
#define SPI_CR2_DS_POS          8
#define SPI_CR2_FRXTH           (1U << 12)
#define SPI_CR2_LDMA_RX         (1U << 13)
#define SPI_CR2_LDMA_TX         (1U << 14)
// Status register
#define SPI_SR_RXNE             1U
#define SPI_SR_TXE             (1U << 1)

#define SPI1_AF         5U      // 0b0101
#define SPI1_SCK_POS    5       // PA5
#define SPI1_MISO_POS   6       // PA6
#define SPI1_MOSI_POS   7       // PA7

#define SPI3_AF         6U      // 0b0110
#define SPI3_SCK_POS    3       // PB3
#define SPI3_MISO_POS   4       // PB4
#define SPI3_MOSI_POS   5       // PB5

#define SPI1_IRQn       35U     // SPI1 interrupt
#define SPI2_IRQn       36U     // SPI2 interrupt
#define SPI3_IRQn       51U     // SPI3 interrupt

void spi1_master_cfg(void);
void spi3_slave_cfg(void);
void spi_en(SPI_reg_t *SPIx);

#endif