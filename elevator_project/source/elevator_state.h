/**
* @file
* @brief State machine.
*
*/
#ifndef ELEVATOR_STATE_H
#define ELEVATOR_STATE_H

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
    HardwareOrder dir;
} Order;

/**
* @brief Elevator state.
*/
Order* ELEVATOR_STATE;

#include "request_handler.h"
#include "motor_state.h"

/**
* @brief
*/
void initialize_elevator_state();

/**
* @brief
*/
void update_elevator_pos();

/**
* @brief
* @return floor.
*/
 int go_to_defined_pos();


/**
* @brief
*/
void elevator_state_update_floor_light();

#endif
