/*
 * traffic_light.c
 *
 *  Created on: Nov 15, 2023
 *      Author: DELL
 */

#include "traffic_light.h"

uint8_t red = DEFAUFT_RED, yellow = DEFAUFT_YELLOW, green = DEFAUFT_GREEN;

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

/*
 * Get led red time duration
 * input: none
 * output: time duration
 * */
uint8_t getRed()
{
	return red;
}

/*
 * Get led yellow time duration
 * input: none
 * output: time duration
 * */
uint8_t getYellow()
{
	return yellow;
}

/*
 * Get led green time duration
 * input: none
 * output: time duration
 * */
uint8_t getGreen()
{
	return green;
}
