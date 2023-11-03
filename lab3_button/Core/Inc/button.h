/*
 * button.h
 *
 *  Created on: Nov 3, 2023
 *      Author: DELL
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "queue.h"

#define MAX_BUTTON 3

uint8_t is_button_pressed(uint8_t index);
void get_input_key(uint8_t index);


#endif /* INC_BUTTON_H_ */
