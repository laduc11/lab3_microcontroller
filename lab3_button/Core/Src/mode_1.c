/*
 * mode_1.c
 *
 *  Created on: Nov 3, 2023
 *      Author: DELL
 */

#include "mode_1.h"
#include "software_timer.h"		/* Software timer 0-4 */


/*
 * Init sate
 * para: none
 * return: none
 * */
void init_state()
{
	// set up initial variable
	set_timer(0, 2);
}

void fsm_mode_1(state name)
{
	switch (name)
	{
	case INIT:
		init_state();
		break;
	case RED_GREEN:

		break;
	case RED_YELLOW:
		break;
	case GREEN_RED:
		break;
	case YELLOW_RED:
		break;
	default:
		init_state();
	}
}

