/*
 * state.h
 *
 *  Created on: Dec 30, 2023
 *      Author: Seifeldin Ahmed Ismail
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"

//Automatic STATE Function generated
#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_)  ST_##_statFUN_

// States Connection (interfaces between moduels)
/* implementation of these functions be in the destination */
void US_set_distance (int distance);
void DC_Motor_Set(int speed);


#endif /* STATE_H_ */
