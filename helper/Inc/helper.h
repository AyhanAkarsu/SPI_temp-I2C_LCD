/*
 * helper.h
 *
 *  Created on: 11 Mar 2025
 *      Author: Ayhan
 */

#ifndef INC_HELPER_H_
#define INC_HELPER_H_

#include "stm32f4xx_hal.h"
#include "stdio.h"

float ConvertTemperature(uint16_t rawData);

char* toString(float data);


#endif /* INC_HELPER_H_ */
