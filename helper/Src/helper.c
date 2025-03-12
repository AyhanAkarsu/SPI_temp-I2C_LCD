/*
 * helper.c
 *
 *  Created on: 11 Mar 2025
 *      Author: Ayhan
 */

#include "helper.h"

char* toString(float data)
{
	static char buffer[15];
	snprintf(buffer, sizeof(buffer), "Sicaklik: %.2f", data);
	return buffer;
}

float ConvertTemperature(uint16_t rawData)
{
	int16_t signedData = (int16_t)(rawData & 0xFFF8);
	signedData >>= 3;

	float temperature = signedData * 0.0625f;

	return temperature;
}
