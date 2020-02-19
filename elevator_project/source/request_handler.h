/**
* @file
* @brief Request handler.
*
*/
#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

#include "hardware.h"
#include "elevator_state.h"
#include <stdio.h>
#include <stdlib.h>

/**
* @brief
*/
Order destinations[HARDWARE_NUMBER_OF_FLOORS];

/**
* @brief
*/
Order orders[HARDWARE_NUMBER_OF_ORDER_BUTTONS];

/**
* @brief
*/
void place_order(Order* op);

/**
* @brief
*/
void destination_sort_ascending();

/**
* @brief
*/
void destination_sort_descending();

/**
* @brief
*/
void swap(Order *o1, Order *o2);

/**
* @brief
*/
void fillDestination();

/**
* @brief
*/
void deleteFirstDestination();

/**
* @brief
*/
void clear_orders();

#endif
