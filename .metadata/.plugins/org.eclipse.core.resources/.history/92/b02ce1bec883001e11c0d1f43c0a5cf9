/*
 * mode2.c
 *
 *  Created on: Nov 15, 2023
 *      Author: DELL
 */

#include "mode2.h"

MODE2_STATE state;
uint8_t red;

void mode2()
{
	switch (state)
	{
	case MODE2_INIT:
		HAL_GPIO_WritePin(GPIOA, H_RED_Pin|H_YELLOW_Pin|H_GREEN_Pin|
								 V_RED_Pin|V_YELLOW_Pin|V_GREEN_Pin, SET);
		state = MODE2_INCREASE;
		red = getRed();
		break;
	case MODE2_INCREASE:
		// increase time duration
		displayHorizon(red);
		if (isPressed(1))
		{
			red++;
			if (red > 99)
				red = 0;
		}
		break;
	case MODE2_SET_TIME:
		// set time duration
		setRed(red);
		break;
	default:
		break;
	}
}

void setState2(MODE2_STATE cur_state)
{
	state = cur_state;
}
