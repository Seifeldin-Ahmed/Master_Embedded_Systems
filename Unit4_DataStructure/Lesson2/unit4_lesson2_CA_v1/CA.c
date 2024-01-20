/*
 * CA.c
 *
 *  Created on: Dec 30, 2023
 *      Author: Seifeldin Ahmed Ismail
 */


#include "CA.h"


//variables
static int CA_speed = 0;
static int CA_distance = 0;
static int CA_threshold = 50;

//STATE Pointer to function
void (*CA_state)();
int US_Get_distance_random (int min, int max);

STATE_define(CA_waiting)
{
	//state_Name
	CA_state_id = CA_waiting ;

	//state_Action
	CA_speed = 0;
    //DC_Motor(CA_speed)

	//Event_Check
	//US_Get_distance(&CA_distance);
	CA_distance = US_Get_distance_random(45,55);
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)): (CA_state = STATE(CA_driving)) ;
	printf("CA_Waiting State: distance=%d  Speed=%d \n",CA_distance , CA_speed);
}
STATE_define(CA_driving)
{
	//state_Name
	CA_state_id = CA_driving ;

	//state_Action
	CA_speed = 30;
	//DC_Motor(CA_speed)

	//Event_Check
	//US_Get_distance(&CA_distance);
	CA_distance = US_Get_distance_random(45,55);
	(CA_distance > CA_threshold)? (CA_state = STATE(CA_driving)): (CA_state = STATE(CA_waiting)) ;
	printf("CA_Driving State: distance=%d  Speed=%d \n",CA_distance , CA_speed);
}

int US_Get_distance_random(int min, int max)
{
	//this will generate random numbers on range min and max
	int rand_num = (rand() % (max - min + 1)) + 1;
	return rand_num;
}

