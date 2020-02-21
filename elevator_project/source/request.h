/**
* @file
* @brief Request handler.
*
*/
#ifndef REQUEST_H
#define REQUEST_H

#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "elevator_state.h"
#include "door.h"

typedef struct {
    Floor pos;
    HardwareOrder dir;
} Order;

/**
* @brief Array for elevator target priorities.
*/
Order destinations[HARDWARE_NUMBER_OF_FLOORS];

/**
* @brief Array for elevator target sub-priorities.
*/
Order orders[HARDWARE_NUMBER_OF_ORDER_BUTTONS];

/**
* @brief
*/
void request_place_order(Order* op);

/**
* @brief
*/
void request_destination_sort_ascending();

/**
* @brief
*/
void request_destination_sort_descending();

/**
* @brief
*/
void request_swap_order(Order *o1, Order *o2);

/**
* @brief
*/
void request_fill_destination();

/**
* @brief
*/
void request_delete_first_destination();

/**
* @brief
*/
void clear_orders();

/**
* @brief
*/
void clear_destinations();

#endif
