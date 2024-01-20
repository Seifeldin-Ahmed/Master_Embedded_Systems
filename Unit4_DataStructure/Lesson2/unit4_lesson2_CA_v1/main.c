/*
 * main.c
 *
 *  Created on: Dec 30, 2023
 *      Author: Seifeldin Ahmed Ismail
 */
#include "CA.h"

void setup()
{
	//init all the drivers
	//init IRQ....
	//init HA US_Driver DC_Driver
	//init BLOCK
	//Set States Pointers for each block
	CA_state = STATE(CA_waiting);
}

int main()
{
	volatile int delay;
	setup();

	while(1)
	{
		//call state for each block
		CA_state();
        //delay
		for(delay=0 ; delay<5000;delay++);
	}

	return 0;
}
