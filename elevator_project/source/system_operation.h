/**
* @file
* @brief Hardware input.
*
*/
#ifndef SYSTEM_OPERATION_H
#define SYSTEM_OPERATION_H

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

#include "hardware.h"
#include "hardware_input.h"
#include "elevator_state.h"
#include "motor_state.h"
#include "start_system.h"
#include "request.h"

/**
 * @brief Time door is kept open.
 */
#define IDLE_TIME 1;

 /**
 * @brief Displays the the the position and direction of the elevator, and the elemets in both destinations and orders.
 */
void print_operating_info();

/**
 * Performes the stop-procedure.
 *
 * @param[out] destinations Is cleared
 * @param[out] orders Is cleared
 * @param[out] ELAVATOR_STATE direction is set to HARDWARE_MOVEMENT_STOP
 */
void stop_elevator();

/**
 * @brief Orchestrates the necessary procedure for running the elevator system.
 */
void system_operation_run();

#endif
