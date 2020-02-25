/**
* @file
* @brief Motor state.
*
*/
#ifndef MOTOR_STATE_H
#define MOTOR_STATE_H
#include "system_operation.h"

/**
* @brief
*/
clock_t time_wait;

/**
* @brief Either fills up the destination-list, or send a new destination to motor_state_elevator_transistion
*/
void motor_state_move_elevator();

/**
 * @brief Sets the movement of the elevator based on the difference between the current position and destination
 *
 * @param [in] dest The destination floor
 * @param [in] pos The current position of the elevator
 * @param [out] ELEVATOR_STATE direction is changed
 *
 */
void transition_actuation(Floor dest, Floor pos);


#endif
