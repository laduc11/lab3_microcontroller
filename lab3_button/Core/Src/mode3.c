/*
 * mode3.c
 *
 *  Created on: Nov 15, 2023
 *      Author: DELL
 */

#include "mode3.h"

MODE3_STATE state;
uint8_t mod_yellow;

void mode3()
{
	switch (state)
	{
	case MODE3_INIT:
		HAL_GPIO_WritePin(GPIOA, H_RED_Pin|H_YELLOW_Pin|H_GREEN_Pin|
								 V_RED_Pin|V_YELLOW_Pin|V_GREEN_Pin, SET);
		state = MODE3_INCREASE;
		mod_yellow = getYellow();
		break;
	case MODE3_INCREASE:
		// increase time duration
		displayHorizon(mod_yellow);
		if (isPressed(1))
		{
			mod_yellow++;
			if (mod_yellow > 99)
				mod_yellow = 0;
		}
		break;
	case MODE3_SET_TIME:
		// set time duration
		setYellow(mod_yellow);
		break;
	default:
		state = MODE3_INIT;
		break;
	}
}

void setState3(MODE3_STATE cur_state)
{
	state = cur_state;
}

