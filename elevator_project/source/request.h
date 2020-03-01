/**
* @file
* @brief Defines two order arrays to keep track of requests from users. 
* Responsible for the logic of placing a new order and deleting the current order.
*
*/
#ifndef REQUEST_H
#define REQUEST_H

#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "elevator_state.h"
#include "system_operation.h"

/**
 *@brief Struct used in array @c destinations and array @c queue.
 */

typedef struct {
    Floor pos;
    HardwareOrder dir;
} Order;

/**
* @brief Undefined @c Order to initialize and reset @c destinations and @c queue.
*/
#define ORDER_UNDEF {undef, HARDWARE_ORDER_INSIDE}

/**
 * @brief Sort mode used in @c order_arr_sort_pos to sort elements descending or ascending
 */
typedef enum {
	descending = -1,
	ascending = 1
} SortMode;

/**
* @brief Orders continuosly sorted in presceding elevator direction.
* Elements are given the undefinite order type @c ORDER_UNDEF when not in use.
* First element gives the nearest destination for @c motor_state.h to set motor actuation.
* The array are used in 
*/
Order destinations[HARDWARE_NUMBER_OF_FLOORS];

/**
* @brief Contains orders for @c pos or @c dir in none-presceding elevator direction. 
* Chronological. Sub-priorities.
* Used in @c request_fill_destinations_from_queue to 
*/
Order queue[HARDWARE_NUMBER_OF_ORDER_BUTTONS];

/**
* @brief Checks if @c op exist in @c destinations or @c orders, and preceed to place Order to @c destinations or @c orders based upon the member values and logic.
*/
void request_place_order(Order* op);

/**
* @brief deletes the first element in destinations and move the remainding elements one place towards the front
*/
void request_delete_current_destination();

/**
* @brief Fills up the destinations list with elements from the order list
*/
void request_fill_destinations_from_queue();

/**
* @brief .
*/
void request_clear_orders();

/**
* @brief .
*/
int check_order_handled(Order *op);

/**
* @brief Swaps the pointers of two Order elements
*/
void swap_order(Order *o1, Order *o2);

/**
* @brief Puts the valid elements in the destinations-list in ascending order
*
* @param S sort mode. -1 for descending and 1 for ascending.
*/
void order_arr_sort_pos(Order *arr, int i_max, SortMode S);

/**
* @brief Removes all elements in orders and replaces them with invalid elements
*/
void order_arr_clear(Order *arr, int i_max);

/**
* @brief .
*/
void order_arr_shift_to_start(Order *arr, int i_max);

/**
* @brief Places an order element at the back of the order array.
*/

void push_to_queue(Order *op);



#endif
