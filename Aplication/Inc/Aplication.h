/*
 * Aplication.h
 *
 *  Created on: Mar 6, 2025
 *      Author: Ayhan
 */

#ifndef INC_APLICATION_H_
#define INC_APLICATION_H_

#include "I2C_Init.h"
#include "SPI_Init.h"
#include "helper.h"
#include <string.h>
#include <stdlib.h>

#define JHD_2x16_LCD_ADDRESS            0x3E

char* TC77_TempRead();

void sendDataTemp_JHD_2X16(const char* temp);

void readAndSendTemperature(void);

void clearToScreen_JHD_2X16();

#endif /* INC_APLICATION_H_ */
