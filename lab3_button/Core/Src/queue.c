/*
 * queue.c
 *
 *  Created on: Nov 3, 2023
 *      Author: DELL
 */

#include "queue.h"

QUEUE queue;

void init_queue()
{
	for (int i = 0; i < SIZE; i++)
		queue.data[i] = 0;
}

uint8_t is_on()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (queue.data[i] == 0)
			return 0;
	}
	return 1;
}

void enqueue(uint8_t data)
{
	queue.data[SIZE - 1] = data;
}

uint8_t dequeue()
{
	uint8_t front = queue.data[0];
	for (int i = 0; i < SIZE - 1; i++)
	{
		queue.data[i] = queue.data[i + 1];
	}
	return front;
}
