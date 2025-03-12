/*
 * I2C_Init.c
 *
 *  Created on: Mar 6, 2025
 *      Author: Ayhan
 */

#include "I2C_Init.h"


void I2C_Init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

	GPIOB->MODER &= ~(GPIO_MODER_MODE6 | GPIO_MODER_MODE7);
	GPIOB->MODER |= (2 << GPIO_MODER_MODE6_Pos) | (2 << GPIO_MODER_MODE7_Pos);

	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT6 | GPIO_OTYPER_OT7);
	GPIOB->OTYPER |= GPIO_OTYPER_OT6 | GPIO_OTYPER_OT7;

	GPIOB->AFR[0] &= (GPIO_AFRL_AFRL6 | GPIO_AFRL_AFRL7);
	GPIOB->AFR[0] |= (4 << GPIO_AFRL_AFSEL6_Pos) | (4 << GPIO_AFRL_AFSEL7_Pos);

	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;

	I2C1->CR1 &= ~I2C_CR1_PE;

	I2C1->CR2 |= (16 << I2C_CR2_FREQ_Pos);

	I2C1->CCR |= 80;

	I2C1->TRISE = 17;

	I2C1->CR1 |= I2C_CR1_PE;
}

void I2C_SendDataString(const char* data, uint8_t address)
{
	I2C1->CR1 |= I2C_CR1_START;

	while(!(I2C1->SR1 & I2C_SR1_SB));

	I2C1->DR = (address << 1);
	while(!(I2C1->SR1 & I2C_SR1_ADDR));
	(void)I2C1->SR2;

	I2C1->DR = 0x40;
	while(!(I2C1->SR1 & I2C_SR1_BTF));
	while(*data)
	{
		I2C1->DR = *data++;
		while(!(I2C1->SR1 & I2C_SR1_BTF));
	}

	I2C1->CR1 |= I2C_CR1_STOP;
}

void sendToCommand(uint8_t command, uint8_t address)
{
	I2C1->CR1 |= I2C_CR1_START;
	while(!(I2C1->SR1 & I2C_SR1_SB));

	I2C1->DR = (address << 1);
	while(!(I2C1->SR1 & I2C_SR1_ADDR));
	(void)I2C1->SR2;

	I2C1->DR = 0x00;
	while(!(I2C1->SR1 & I2C_SR1_BTF));

	I2C1->DR = command;
	while(!(I2C1->SR1 & I2C_SR1_BTF));

	I2C1->CR1 |= I2C_CR1_STOP;
}
