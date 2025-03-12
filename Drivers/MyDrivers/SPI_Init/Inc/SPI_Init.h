/*
 * SPI_Init.h
 *
 *  Created on: Mar 6, 2025
 *      Author: Ayhan
 */

#ifndef MYDRIVERS_SPI_INIT_INC_SPI_INIT_H_
#define MYDRIVERS_SPI_INIT_INC_SPI_INIT_H_

#include "stm32f4xx_hal.h"


void SPI_Init(void);

uint16_t SPI_ReadData(void);

#endif /* MYDRIVERS_SPI_INIT_INC_SPI_INIT_H_ */
