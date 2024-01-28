/*
 * MainAlg.h
 *
 *   Created on: Jun 25, 2024
 *      Author: Seifeldin Ahmed Ismail
 */

#ifndef MAINALG_H_
#define MAINALG_H_

#include "state.h"

//Define States
enum {
	MainAlg_high_pressure_detection
}MainAlg_state_id;


//declare states functions MainAlg
STATE_define(MainAlg_high_pressure_detection);


//STATE Pointer to function
extern void (*MainAlg_state)();

#endif /* MAINALG_H_ */
