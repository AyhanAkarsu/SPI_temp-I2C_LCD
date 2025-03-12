#include "SPI_Init.h"

void SPI_Init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	// GPIO Ayarları
	GPIOA->MODER &= ~((3 << GPIO_MODER_MODE4_Pos) | (3 << GPIO_MODER_MODE5_Pos) | (3 << GPIO_MODER_MODE6_Pos));
	GPIOA->MODER |= (2 << GPIO_MODER_MODE5_Pos) | (2 << GPIO_MODER_MODE6_Pos); // AF Mode
	GPIOA->MODER |= (1 << GPIO_MODER_MODE4_Pos); // Output Mode (NSS)

	// Alternatif Fonksiyon Ayarı
	GPIOA->AFR[0] &= ~((0xF << GPIO_AFRL_AFSEL5_Pos) | (0xF << GPIO_AFRL_AFSEL6_Pos));
	GPIOA->AFR[0] |= (5 << GPIO_AFRL_AFSEL5_Pos) | (5 << GPIO_AFRL_AFSEL6_Pos);

	GPIOA->ODR |= GPIO_ODR_OD4; // CS High (Bağlantı Kapalı)

	// SPI Saat Aktifleştirme
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

	// SPI Konfigürasyonu
	SPI1->CR1 = 0;
	SPI1->CR1 |= (2 << 3);  // fPCLK / 8 (Baud Rate)
	SPI1->CR1 |= SPI_CR1_MSTR | SPI_CR1_SSM | SPI_CR1_SSI;

	SPI1->CR1 |= SPI_CR1_SPE; // SPI Enable
}

uint16_t SPI_ReadData(void)
{
	uint16_t raw_temprature;
	uint8_t temprature[2];

	GPIOA->ODR &= ~GPIO_ODR_OD4; // CS Low (Başlat)

	while(SPI1->SR & SPI_SR_BSY);
	while(!(SPI1->SR & SPI_SR_TXE));
	SPI1->DR = 0xFF;

	while(!(SPI1->SR & SPI_SR_RXNE));
	temprature[0] = SPI1->DR;

	while(SPI1->SR & SPI_SR_BSY);
	while(!(SPI1->SR & SPI_SR_TXE));
	SPI1->DR = 0xFF;

	while(!(SPI1->SR & SPI_SR_RXNE));
	temprature[1] = SPI1->DR;

	raw_temprature = (temprature[0] << 8) | temprature[1];

	GPIOA->ODR |= GPIO_ODR_OD4; // CS High (Bitti)

	return raw_temprature;
}
