/*
 * mode4.h
 *
 *  Created on: Nov 15, 2023
 *      Author: DELL
 */

#ifndef INC_MODE4_H_
#define INC_MODE4_H_

#include "main.h"

typedef enum mode4_state
{
	MODE4_INIT = 0,
	MODE4_INCREASE = 1,
	MODE4_SET_TIME = 2
} MODE4_STATE;

void setState4(MODE4_STATE cur_state);
void mode4();

#endif /* INC_MODE4_H_ */
