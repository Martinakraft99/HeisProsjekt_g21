#include "hardware.h"
#include "elevator_state.h"
#include "request_handler.h"


#ifndef motor_state_h
#define motor_state_h


void motorStateMachine(Floor dest, Floor pos);
void move_elevator();


#endif
