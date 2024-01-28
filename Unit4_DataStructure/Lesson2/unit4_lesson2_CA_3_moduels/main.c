/*
 * main.c
 *
 *  Created on: Dec 30, 2023
 *      Author: Seifeldin Ahmed Ismail
 */
#include "CA.h"
#include "US.h"
#include "DC.h"
void setup()
{
	//init all the drivers
	//init IRQ....
	//init HA US_Driver DC_Driver
	//init BLOCK
	US_init();
	DC_init();
	//Set States Pointers for each block
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}

int main()
{
	volatile int delay;
	setup();

	while(1)
	{
		//call state for each block
		US_state();
		CA_state();
		DC_state();
        //delay
		for(delay=0 ; delay<90000000;delay++);
	}

	return 0;
}
