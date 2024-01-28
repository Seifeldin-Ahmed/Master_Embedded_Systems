/*
 * PressureSensorDriver.h
 *
 *  Created on: Jun 25, 2024
 *      Author: Seifeldin Ahmed Ismail
 */

#ifndef PressureSensorDriver_H_
#define PressureSensorDriver_H_

#include "state.h"

//Define States
enum {
	PressureSensorDriver_reading
}PressureSensorDriver_state_id;


//declare states functions PressureSensorDriver
STATE_define(PressureSensorDriver_reading);

//methods
void PressureSensorDriver_init();


//STATE Pointer to function
extern void (*PressureSensorDriver_state)();

#endif /* PressureSensorDriver_H_ */
