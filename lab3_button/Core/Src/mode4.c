/*
 * mode4.c
 *
 *  Created on: Nov 15, 2023
 *      Author: DELL
 */

#include "mode4.h"

MODE4_STATE state;

void mode4()
{
	switch (state)
	{
	case MODE4_INIT:
		HAL_GPIO_WritePin(GPIOA, H_RED_Pin|H_YELLOW_Pin|H_GREEN_Pin|
								 V_RED_Pin|V_YELLOW_Pin|V_GREEN_Pin, SET);
		state = MODE4_INCREASE;
		break;
	case MODE4_INCREASE:
		// increase time duration
		break;
	case MODE4_SET_TIME:
		// set time duration
		break;
	default:
		break;
	}
}

void setState4(MODE4_STATE cur_state)
{
	state = cur_state;
}
