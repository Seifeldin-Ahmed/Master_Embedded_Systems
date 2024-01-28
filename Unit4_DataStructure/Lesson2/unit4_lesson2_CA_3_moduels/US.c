/*
 * US.c
 *
 *  Created on: Dec 30, 2023
 *      Author: Seifeldin Ahmed Ismail
 */


#include "US.h"


//variables
static int US_distance = 0;

//STATE Pointer to function
void (*US_state)();
int US_Get_distance_random (int min, int max);

void US_init()
{
	//init US Driver
	printf("US_init \n");
}
STATE_define(US_busy)
{
	//state_Name
	US_state_id = US_busy ;

	//state_Action
	US_distance = US_Get_distance_random(45,55); //get distance value
	US_set_distance(US_distance); //send signal
	US_state = STATE(US_busy); // back to busy state

	printf("US_busy State: distance=%d \n",US_distance);
}


int US_Get_distance_random(int min, int max)
{
	//this will generate random numbers on range min and max
	int rand_num = (rand() % (max - min + 1)) + 1;
	return rand_num;
}

