/**
* @file
* @brief Start up progress for elevator.
*
*/
#ifndef START_SYSTEM_H
#define START_SYSTEM_H

#include "hardware.h"
#include "elevator_state.h"

/**
* @brief Sigint handler.
*/
void sigint_handler(int sig);


/**
* @brief Start up of the system.
*/
void start_system();

#endif
