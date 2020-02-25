/**
* @file
* @brief State machine.
*
*/
#ifndef ELEVATOR_STATE_H
#define ELEVATOR_STATE_H

#include <stdio.h>
#include "hardware.h"

/**
* @brief Floor position used in struct @c Order.
*/
typedef enum { undef = -1, first, second, third, fourth } Floor;

/**
* @brief Position and direction for the elevator.
*/
typedef struct {
    Floor pos;
    HardwareMovement dir;
} Elevator;

#include "system_operation.h"

/**
* @brief Global elevator state.
*/
Elevator *ELEVATOR_STATE;

/**
* @brief initialize the elevator-struct with a valid position and direction
*/
void elevator_state_initialize();

/**
* @brief
*/
void elevator_state_update_pos();

/**
* @brief Moves the elevator to a defined position
* @return floor.
*/
 int elevator_state_go_to_defined_pos();

#endif
