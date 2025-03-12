/*
 * I2C_Init.h
 *
 *  Created on: Mar 6, 2025
 *      Author: Ayhan
 */

#ifndef MYDRIVERS_I2C_INIT_INC_I2C_INIT_H_
#define MYDRIVERS_I2C_INIT_INC_I2C_INIT_H_

#include "stm32f4xx_hal.h"

void I2C_Init(void);

void I2C_SendDataString(const char* data, uint8_t address);

void sendToCommand(uint8_t command, uint8_t address);

#endif /* MYDRIVERS_I2C_INIT_INC_I2C_INIT_H_ */
