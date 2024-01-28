/*
 * DC.h
 *
 *  Created on: Dec 30, 2023
 *      Author: Seifeldin Ahmed Ismail
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"

//Define States
enum {
	DC_idle,
	DC_busy
}DC_state_id;


//declare states functions DC
STATE_define(DC_idle);
STATE_define(DC_busy);

//methods
void DC_init();

//STATE Pointer to function
extern void (*DC_state)();

#endif /* DC_H_ */
