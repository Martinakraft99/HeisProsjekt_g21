/**
* @file
* @brief Motor state.
*
*/
#ifndef MOTOR_STATE_H
#define MOTOR_STATE_H

#include <time.h>
#include <stdio.h>
#include "hardware.h"
#include "elevator_state.h"
#include "request.h"
#include "hardware_input.h"
/**
* @brief
*/
clock_t time_wait;

/**
* @brief
*/
void motor_state_transition(Floor dest, Floor pos);

/**
* @brief
*/
void motor_state_move_elevator();

#endif
