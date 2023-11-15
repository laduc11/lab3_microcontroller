/*
 * mode2.h
 *
 *  Created on: Nov 15, 2023
 *      Author: DELL
 */

#ifndef INC_MODE2_H_
#define INC_MODE2_H_

#include "main.h"

typedef enum mode2_state
{
	MODE2_INIT = 0,
	MODE2_INCREASE = 1,
	MODE2_SET_TIME = 2
} MODE2_STATE;

void setState2(MODE2_STATE cur_state);
void mode2();

#endif /* INC_MODE2_H_ */
