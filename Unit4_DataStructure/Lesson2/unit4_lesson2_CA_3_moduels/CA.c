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


// interface between this moduel and US
void US_set_distance (int distance)
{
	CA_distance = distance;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)): (CA_state = STATE(CA_driving)) ;
    printf("US ------- Distance = %d ----------> CA \n",CA_distance);
}
STATE_define(CA_waiting)
{
	//state_Name
	CA_state_id = CA_waiting ;

	//state_Action
	CA_speed = 0;
    DC_Motor_Set(CA_speed);

	//Event_Check
	printf("CA_Waiting State: distance=%d  Speed=%d \n",CA_distance , CA_speed);
}
STATE_define(CA_driving)
{
	//state_Name
	CA_state_id = CA_driving ;

	//state_Action
	CA_speed = 30;
    DC_Motor_Set(CA_speed);

	//Event_Check
	printf("CA_Driving State: distance=%d  Speed=%d \n",CA_distance , CA_speed);
}

