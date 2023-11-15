/*
 * mode2.c
 *
 *  Created on: Nov 15, 2023
 *      Author: DELL
 */

#include "mode2.h"

MODE2_STATE state;
uint8_t mod_red;

void mode2()
{
	switch (state)
	{
	case MODE2_INIT:
		HAL_GPIO_WritePin(GPIOA, H_RED_Pin|H_YELLOW_Pin|H_GREEN_Pin|
								 V_RED_Pin|V_YELLOW_Pin|V_GREEN_Pin, SET);
		state = MODE2_INCREASE;
		mod_red = getRed();
		break;
	case MODE2_INCREASE:
		// increase time duration
		displayHorizon(mod_red);
		if (isPressed(1))
		{
			mod_red++;
			if (mod_red > 99)
				mod_red = 0;
		}
		break;
	case MODE2_SET_TIME:
		// set time duration
		setRed(mod_red);
		break;
	default:
		state = MODE2_INIT;
		break;
	}
}

void setState2(MODE2_STATE cur_state)
{
	state = cur_state;
}
