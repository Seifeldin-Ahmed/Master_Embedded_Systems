/*
 * DC.c
 *
 *  Created on: Dec 30, 2023
 *      Author: Seifeldin Ahmed Ismail
 */


#include "DC.h"


//variables
static int DC_speed = 0;

//STATE Pointer to function
void (*DC_state)();


void DC_init()
{
	//init PWM
	printf("DC_init \n");
}

// interface between this moduel and CA
void DC_Motor_Set(int speed)
{
	DC_speed = speed ;
	DC_state = STATE(DC_busy); // when the event trigered this will direct me to busy state
    printf("CA ------- Speed = %d ----------> DC \n",DC_speed);
}

STATE_define(DC_idle)     // no changes happen in DC Motor in the idle state
{
	//state_Name
	DC_state_id = DC_idle ;

	printf("DC_idle State: Speed=%d \n",DC_speed);
}
STATE_define(DC_busy)
{
	//state_Name
	DC_state_id = DC_busy ;

	//state_Action
	/* call PWM to make Speed = DC_speed */
	DC_state = STATE(DC_idle);

	printf("DC_busy State: Speed=%d \n",DC_speed);
}


