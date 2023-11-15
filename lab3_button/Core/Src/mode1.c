/*
 * mode1.c
 *
 *  Created on: Nov 15, 2023
 *      Author: DELL
 */

#include "mode1.h"

uint8_t H_counter = 0, V_counter = 0;
uint8_t red = DEFAUFT_RED, yellow = DEFAUFT_YELLOW, green = DEFAUFT_GREEN;
TRAFFIC state;

/*
 * run mode 1 in state machine
 * input: none
 * output: none
 * */
void mode1()
{
	switch (state)
	{
	case INIT:
		HAL_GPIO_WritePin(GPIOA, H_RED_Pin|H_YELLOW_Pin|H_GREEN_Pin|
								 V_RED_Pin|V_YELLOW_Pin|V_GREEN_Pin, SET);
		H_counter = 0;
		V_counter = 0;
		displayHorizon(0);
		displayVertical(0);
		break;
	case RED_GREEN:
		if (H_counter == 0)
			H_counter = red;
		if (V_counter == 0)
			V_counter = green;
		HAL_GPIO_WritePin(GPIOA, H_RED_Pin|
								 V_GREEN_Pin, RESET);
		H_counter--;
		V_counter--;
		displayHorizon(H_counter);
		displayVertical(V_counter);
		if (V_counter == 0)
			state = RED_YELLOW;
		break;
	case RED_YELLOW:
		break;
	case GREEN_RED:
		break;
	case YELLOW_RED:
		break;
	default:
		break;
	}
}

/*
 * Set state for mode 1
 * input: current state
 * output: none
 * */
void setState(TRAFFIC cur_state)
{
	state = cur_state;
}
