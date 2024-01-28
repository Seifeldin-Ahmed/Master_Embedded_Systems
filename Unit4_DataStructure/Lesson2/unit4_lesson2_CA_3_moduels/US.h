/*
 * US.h
 *
 *  Created on: Dec 30, 2023
 *      Author: Seifeldin Ahmed Ismail
 */

#ifndef US_H_
#define US_H_

#include "state.h"

//Define States
enum {
	US_busy
}US_state_id;


//declare states functions US
STATE_define(US_busy);

//methods
void US_init();


//STATE Pointer to function
extern void (*US_state)();

#endif /* US_H_ */
