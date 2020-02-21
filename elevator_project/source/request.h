/**
* @file
* @brief Defines an order, and is responsible the arrays containing them. 
* 
*/
#ifndef REQUEST_H
#define REQUEST_H

#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "elevator_state.h"
#include "door.h"

/**
 *@brief Defines a order 
 */
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
* @brief Places an order into either destinations or orders based upon the member values of the order and current elements in the lists
*/
void request_place_order(Order* op);

/**
* @brief Puts the valid elements in the destinations-list in ascending order
*/
void request_destination_sort_ascending();

/**
* @brief Puts the valid elements in the destinations-list in descending order
*/
void request_destination_sort_descending();

/**
* @brief Swaps the pointers of two Order elements
*/
void request_swap_order(Order *o1, Order *o2);

/**
* @brief Fills up the destinations list with elements from the order list
*/
void request_fill_destination();

/**
* @brief deletes the first element in destinations and move the remainding elements one place towards the front
*/
void request_delete_first_destination();

/**
* @brief Removes all elements in order and replaces them with invalid elements 
*/
void clear_orders();

/**
* @brief Removes all elements in destinations and replaces them with invalid elements 
*/
void clear_destinations();

#endif
