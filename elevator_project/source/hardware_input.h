/**
* @file
* @brief Hardware input.
*
*/
#ifndef HARDWARE_INPUT_H
#define HARDWARE_INPUT_H

#include <stdio.h>
#include "elevator_state.h"
#include "hardware.h"



#include "request.h"

/**
* @brief First element in enum @c HardwareOrder used for iterating through elements in function @c hardware_input_take_order.
*/
#define HardwareOrderStart 0
/**
* @brief Last element in enum @c HardwareOrder used for iterating through elements in function @c hardware_input_take_order.
*/
#define HardwareOrderLast 2

/**
* @brief Iterate floors.
*
* @return int floor.
*/
int hardware_input_read_floors();

/**
* @brief
*/
void hardware_input_take_order();

#endif
