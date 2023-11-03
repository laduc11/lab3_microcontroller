/*
 * queue.h
 *
 *  Created on: Nov 3, 2023
 *      Author: DELL
 */

#ifndef INC_QUEUE_H_
#define INC_QUEUE_H_

#include "main.h"

#define SIZE 3

typedef struct queue
{
	uint8_t data[SIZE];
} QUEUE;

void init_queue();
uint8_t is_on();
void enqueue(uint8_t data);
uint8_t dequeue();

#endif /* INC_QUEUE_H_ */
