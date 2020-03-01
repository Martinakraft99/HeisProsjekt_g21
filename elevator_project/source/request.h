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
* Used in @c request_fill_destinations_from_queue to fill @c destinations recursively when no elements in destinations
*/
Order queue[HARDWARE_NUMBER_OF_ORDER_BUTTONS];

/**
* @brief Checks if @c op exist in @c destinations or @c queue, 
* and preceed to place order to @c destinations or @c queue based upon the member values and logic.
*
* @param op order placed
*/
void request_place_order(Order* op);

/**
* @brief deletes the first element in @c destinations and call the function @c order_arr_shift_to_start
* to place remaining elements towards the front
*/
void request_delete_current_destination();

/**
* @brief Makes a copy of @queue and calls @c request_place_order for every order elements in @queue
* to fill up @c destinations when it contains no orders.
*/
void request_fill_destinations_from_queue();

/**
* @brief Call @order_arr_clear for @c destinations and @c queue.
*/
void request_clear_orders();

/**
* @brief Iterates elements in @c destinations to check if one of the elements @c pos equals @c pos for @c op.
*  Iterates elements in @c queue to check if one of the elements equals @c op.
*
* @param op order to be checked.
*
* @return 0 if no match. None-zero for success.
*/
int check_order_handled(Order *op);

/**
* @brief Swaps the pointers of two elements of struct @c Order
*
* @param o1 first order
* @param o2 second order
*/
void swap_order(Order *o1, Order *o2);

/**
* @brief Sorts valid elements in @c arr ascending or descending dependent on @c S.
*
* @param arr order array. Either @c destinations or @c queue.
* @param S sort mode. -1 for descending and 1 for ascending.
* @param i_max max indentation-1 to @c arr.
*/
void order_arr_sort_pos(Order *arr, int i_max, SortMode S);

/**
* @brief Iterates every elements in @c arr set them to @c UNDEF_ORDER.
* @param arr order array to be cleared.
* @param i_max max indentation-1 to @c arr.
*/
void order_arr_clear(Order *arr, int i_max);

/**
* @brief Shifts all valid elements in @c arr to beginning of array. 
* All undefined elements in @c arr placed to right.
*
* @param arr order array.
* @param i_max max indentation-1 for @c arr
*/
void order_arr_shift_to_start(Order *arr, int i_max);

/**
* @brief Places an order element @c op at first place where @c queue contains an undefined order.
* @param op order.
*/

void push_to_queue(Order *op);



#endif
