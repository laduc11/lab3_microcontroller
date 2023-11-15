/*
 * led7seg.c
 *
 *  Created on: Nov 15, 2023
 *      Author: DELL
 */

#include "led7seg.h"

uint8_t buffer[2][2] = {{0,0}, {0,0}};
// enable
uint8_t enable_counter = 0;

/*
 * Display number on 7-segment led
 * input: number range 0-9
 * output: none
 * */
void display7seg(uint8_t num)
{
	switch(num)
	{
	case 0:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, SEG6_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, SEG1_Pin|SEG2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin|SEG1_Pin|SEG3_Pin|SEG4_Pin|SEG6_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, SEG2_Pin|SEG5_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG6_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, SEG4_Pin|SEG5_Pin, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOA, SEG1_Pin|SEG2_Pin|SEG5_Pin|SEG6_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin|SEG3_Pin|SEG4_Pin, SET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin|SEG6_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, SEG1_Pin|SEG4_Pin, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, SEG1_Pin, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin|SEG1_Pin|SEG2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin|SEG6_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, SEG4_Pin, SET);
		break;
	default:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, SET);
		break;
	}
}

/*
 * Display number on vertical 7-segment led
 * input: number range 0-99
 * output: none
 * */
void displayVertical(uint8_t num)
{
	if (num > 99)
		return;
	buffer[1][1] = num % 10;
	buffer[1][0] = num / 10;
}

/*
 * Display number on horizon 7-segment led
 * input: number range 0-99
 * output: none
 * */
void displayHorizon(uint8_t num)
{
	if (num > 99)
		return;
	buffer[0][1] = num % 10;
	buffer[0][0] = num / 10;
}

/*
 * Update 7-segment led
 * input: none
 * output: none
 * */
void update7seg()
{
  if (get_flag(2))
  {
	  set_timer(2, 25);
	  HAL_GPIO_WritePin(GPIOB, ENV0_Pin|ENV1_Pin|ENH0_Pin|ENH1_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, ENV0_Pin << enable_counter, RESET);
	  display7seg(buffer[enable_counter/2][enable_counter%2]);
	  enable_counter++;
	  if (enable_counter > 3)
		  enable_counter = 0;
  }
}
