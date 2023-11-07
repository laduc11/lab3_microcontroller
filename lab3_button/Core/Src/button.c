/*
 * button.c
 *
 *  Created on: Nov 3, 2023
 *      Author: DELL
 */

#include "button.h"

QUEUE key_button[MAX_BUTTON];

uint8_t is_button_pressed(uint8_t index);
void get_input_key(uint8_t index);
