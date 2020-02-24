/**
* @file
* @brief Door state.
*
*/
#ifndef DOOR_H
#define DOOR_H

#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "hardware_input.h"
#include "elevator_state.h"
#include "system_operation.h"

/**
* @brief .
*/
clock_t time_wait;


/**
* @brief .
*/
void door_door_state_machine();

#endif
