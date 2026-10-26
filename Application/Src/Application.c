/*
 * Application.c
 *
 *  Created on: Mar 6, 2025
 *      Author: Ayhan
 */

#include "Application.h"

static char* previousTemp  = NULL;

char* TC77_TempRead()
{
	uint16_t SPIReceived = SPI_ReadData();

	float rawTempData = ConvertTemperature(SPIReceived);

	return toString(rawTempData);
}

void sendDataTemp_JHD_2X16(const char* temp)
{
	clearToScreen_JHD_2X16();
	HAL_Delay(100);
	uint8_t address = JHD_2x16_LCD_ADDRESS;
	I2C_SendDataString(temp, address);
}

void clearToScreen_JHD_2X16()
{
	sendToCommand(0x01, JHD_2x16_LCD_ADDRESS);
}

void readAndSendTemperature()
{
	 char* rawTemp = TC77_TempRead();

	 if(strcmp(rawTemp, previousTemp) != 0)
	 {
		 sendDataTemp_JHD_2X16(rawTemp);
		 if(previousTemp != NULL)
			 free(previousTemp);
		 previousTemp = strdup(rawTemp);
	 }
}
