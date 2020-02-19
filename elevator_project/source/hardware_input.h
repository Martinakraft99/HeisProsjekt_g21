/**
* @file
* @brief Hardware input.
*
*/
#ifndef HARDWARE_INPUT_H
#define HARDWARE_INPUT_H

#include "elevator_state.h"
#include "hardware.h"
#include "request_handler.h"

/**
* @brief
*
* @return int floor.
*/
int hardware_input_read_floors();

/**
* @brief
*/
void hardware_input_take_order();

#endif
