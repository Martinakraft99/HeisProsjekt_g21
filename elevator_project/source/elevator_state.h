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
* @brief
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
* @brief
*/
void elevator_state_initialize();

/**
* @brief
*/
void elevator_state_update_pos();

/**
* @brief
* @return floor.
*/
 int elevator_state_go_to_defined_pos();


/**
* @brief
*/
void elevator_state_update_floor_light();

#endif
