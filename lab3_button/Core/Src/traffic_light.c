/*
 * traffic_light.c
 *
 *  Created on: Nov 15, 2023
 *      Author: DELL
 */

#include "traffic_light.h"

/*
 * Blink led red with frequency = 2Hz
 * input: none
 * output: none
 * */
void blinkRed()
{
	if (get_flag(1))
	{
		set_timer(1, BLINK_LED);
		HAL_GPIO_TogglePin(GPIOA, V_RED_Pin|H_RED_Pin);
	}
}

/*
 * Blink led yellow with frequency = 2Hz
 * input: none
 * output: none
 * */
void blinkYellow()
{
	if (get_flag(1))
	{
		set_timer(1, BLINK_LED);
		HAL_GPIO_TogglePin(GPIOA, V_YELLOW_Pin|H_YELLOW_Pin);
	}
}

/*
 * Blink led green with frequency = 2Hz
 * input: none
 * output: none
 * */
void blinkGreen()
{
	if (get_flag(1))
	{
		set_timer(1, BLINK_LED);
		HAL_GPIO_TogglePin(GPIOA, V_GREEN_Pin|H_GREEN_Pin);
	}
}
