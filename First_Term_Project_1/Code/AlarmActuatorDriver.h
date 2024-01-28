/*
 * AlarmActuatorDriver.h
 *
 *  Created on: Jun 25, 2024
 *      Author: Seifeldin Ahmed Ismail
 */

#ifndef AlarmActuatorDriver_H_
#define AlarmActuatorDriver_H_

#include "state.h"

//Define States
enum {
	AlarmActuatorDriver_waiting,
	AlarmActuatorDriver_AlarmOn,
	AlarmActuatorDriver_AlarmOff
}AlarmActuatorDriver_state_id;


//declare states functions AlarmActuatorDriver
STATE_define(AlarmActuatorDriver_waiting);
STATE_define(AlarmActuatorDriver_AlarmOn);
STATE_define(AlarmActuatorDriver_AlarmOff);

//methods
void AlarmActuatorDriver_init();

//STATE Pointer to function
extern void (*AlarmActuatorDriver_state)();
#endif /* AlarmActuatorDriver_H_ */
