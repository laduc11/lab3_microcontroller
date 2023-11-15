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
	if (get_flag(0))
	{
		set_timer(0, 100);
		switch (state)
		{
		case INIT:
			HAL_GPIO_WritePin(GPIOA, H_RED_Pin|H_YELLOW_Pin|H_GREEN_Pin|
									 V_RED_Pin|V_YELLOW_Pin|V_GREEN_Pin, SET);
			H_counter = 0;
			V_counter = 0;
			displayHorizon(0);
			displayVertical(0);
			set_timer(0, 2);
			break;
		case RED_GREEN:
			if (H_counter == 0)
				H_counter = red;
			if (V_counter == 0)
				V_counter = green;
			HAL_GPIO_WritePin(GPIOA, H_RED_Pin|H_YELLOW_Pin|H_GREEN_Pin|
									 V_RED_Pin|V_YELLOW_Pin|V_GREEN_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, H_RED_Pin|V_GREEN_Pin, RESET);
			H_counter--;
			V_counter--;
			displayHorizon(H_counter);
			displayVertical(V_counter);
			if (V_counter == 0)
				state = RED_YELLOW;
			break;
		case RED_YELLOW:
			if (H_counter == 0)
				H_counter = red;
			if (V_counter == 0)
				V_counter = yellow;
			HAL_GPIO_WritePin(GPIOA, H_RED_Pin|H_YELLOW_Pin|H_GREEN_Pin|
									 V_RED_Pin|V_YELLOW_Pin|V_GREEN_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, H_RED_Pin|V_YELLOW_Pin, RESET);
			H_counter--;
			V_counter--;
			displayHorizon(H_counter);
			displayVertical(V_counter);
			if (V_counter == 0)
				state = GREEN_RED;
			break;
		case GREEN_RED:
			if (H_counter == 0)
				H_counter = green;
			if (V_counter == 0)
				V_counter = red;
			HAL_GPIO_WritePin(GPIOA, H_RED_Pin|H_YELLOW_Pin|H_GREEN_Pin|
									 V_RED_Pin|V_YELLOW_Pin|V_GREEN_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, H_GREEN_Pin|V_RED_Pin, RESET);
			H_counter--;
			V_counter--;
			displayHorizon(H_counter);
			displayVertical(V_counter);
			if (H_counter == 0)
				state = YELLOW_RED;
			break;
		case YELLOW_RED:
			if (H_counter == 0)
				H_counter = yellow;
			if (V_counter == 0)
				V_counter = red;
			HAL_GPIO_WritePin(GPIOA, H_RED_Pin|H_YELLOW_Pin|H_GREEN_Pin|
									 V_RED_Pin|V_YELLOW_Pin|V_GREEN_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, H_YELLOW_Pin|V_RED_Pin, RESET);
			H_counter--;
			V_counter--;
			displayHorizon(H_counter);
			displayVertical(V_counter);
			if (H_counter == 0)
				state = RED_GREEN;
			break;
		default:
			state = INIT;
			break;
		}
	}
}

/*
 * Set state for mode 1
 * input: current state
 * output: none
 * */
void setState1(TRAFFIC cur_state)
{
	state = cur_state;
}

/*
 * Set time duration for led red
 * input: time duration
 * output: none
 * */
void setRed(uint8_t num)
{

}

/*
 * Set time duration for led yellow
 * input: time duration
 * output: none
 * */
void setYellow(uint8_t num)
{

}

/*
 * Set time duration for led green
 * input: time duration
 * output: none
 * */
void setGreen(uint8_t num)
{

}
