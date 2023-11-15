/*
 * traffic_light.h
 *
 *  Created on: Nov 15, 2023
 *      Author: DELL
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"
#include "software_timer.h"

#define BLINK_LED 25

typedef enum traffic
{
	INIT = 0,
	RED_GREEN = 1,
	RED_YELLOW = 2,
	GREEN_RED = 3,
	YELLOW_RED = 4
} TRAFFIC;

void blinkRed();
void blinkYellow();
void blinkGreen();

#endif /* INC_TRAFFIC_LIGHT_H_ */
