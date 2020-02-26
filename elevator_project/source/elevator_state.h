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
* @brief Represent the real-world elevator
*/
typedef struct {
    Floor pos;
    HardwareMovement dir;
} Elevator;

#include "hardware_input.h"
#include "start_system.h"
#include "motor_state.h"
#include "request.h"

/**
* @brief Elevator state.
*/
Elevator* ELEVATOR_STATE;

/**
* @brief initialize the elevator-struct with a valid position and direction
*/
void elevator_state_initialize();

/**
* @brief Update position for elevator and set floor light.
*/
void elevator_state_update_pos();

/**
* @brief Moves the elevator to a defined position
* @return floor.
*/
 int elevator_state_go_to_defined_pos();

#endif
