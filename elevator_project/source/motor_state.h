/**
* @file
* @brief Motor state. Turns destination and current position into a signal for the motor, lights and door.
*
*/
#ifndef MOTOR_STATE_H
#define MOTOR_STATE_H

#include <stdio.h>
#include <time.h>
#include "hardware.h"
#include "elevator_state.h"
#include "request.h"
#include "hardware_input.h"
#include "system_operation.h"

/**
* @brief
*/
const int IDLE_TIME;

/**
* @brief Referance time used in @c system_operation.h to keep track of doors open or not.
*/
clock_t time_door;

/**
 * @brief Sets the movement of the elevator based on the difference between the current position and destination.
 *
 * @param [in] dest The destination floor
 * @param [in] pos The current position of the elevator
 * @param [out] ELEVATOR_STATE direction is changed
 *
 */
void motor_state_transition();

/**
 * @brief Either fills up the @c destinations, or send a new order to @c motor_state_elevator_transistion
 */
void motor_state_move_elevator();

/**
 * @brief Set @c time_door to equal true time incremented by @c IDLE_TIME seconds.
 */
void motor_state_time_inc();

#endif
