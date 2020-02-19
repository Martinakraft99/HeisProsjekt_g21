/**
* @file
* @brief Motor state.
*
*/
#ifndef MOTOR_STATE_H
#define MOTOR_STATE_H

#include "hardware.h"
#include "elevator_state.h"
#include "request_handler.h"

/**
* @brief
*/
void motor_state_transition(Floor dest, Floor pos);

/**
* @brief
*/
void motor_state_move_elevator();

#endif
