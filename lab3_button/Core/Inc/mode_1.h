/*
 * mode_1.h
 *
 *  Created on: Nov 3, 2023
 *      Author: DELL
 */

#ifndef INC_MODE_1_H_
#define INC_MODE_1_H_

#include "main.h"
#include "traffic_light.h"

typedef enum STATE
{
	INIT = 0,
	RED_GREEN = 1,
	RED_YELLOW = 2,
	GREEN_RED = 3,
	YELLOW_RED = 4
} state;

void fsm_mode_1();

#endif /* INC_MODE_1_H_ */
