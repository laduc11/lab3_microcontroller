/*
 * button.c
 *
 *  Created on: Nov 7, 2023
 *      Author: DELL
 */

#include "button.h"

int counter = PRESS_TIME;
uint8_t bFlag = 0;
uint8_t bLongFlag = 0;
GPIO_PinState bState[4] = {GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET};

uint8_t checkState()
{
	if (bState[1] == GPIO_PIN_RESET && bState[2] == GPIO_PIN_RESET && bState[3] == GPIO_PIN_RESET)
		return RESET;
	return SET;
}

uint8_t isPressed()
{
	if (bFlag == 1)
	{
		bFlag = 0;
		return 1;
	}
	return 0;
}

void getKey()
{
	bState[1] = bState[2];
	bState[2] = bState[3];
	bState[3] = HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin);
	if (checkState() == RESET)
	{
		if (bState[0] == GPIO_PIN_SET)
		{
			bFlag = 1;
			bState[0] = GPIO_PIN_RESET;
			counter = PRESS_TIME;
		}
		else
		{
			if (counter == 0)
			{
				bLongFlag = 1;
			}
			else
			{
				counter--;
			}
		}
	}
	else
	{
		counter = PRESS_TIME;
	}
}
