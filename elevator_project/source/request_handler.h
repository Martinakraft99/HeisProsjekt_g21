#include "hardware.h"
#include "elevator_state.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef request_handler_h
#define request_handler_h

typedef struct {
    Floor destination;
    HardwareOrder dir;
} Order;


extern Order destinations[HARDWARE_NUMBER_OF_FLOORS];
extern Order orders[10];


void place_order(Order* op, ElevatorState* ep);
void destination_sort_ascending();
void destination_sort_descending();
void swap(Order *o1, Order *o2);
void fillDestination();
void deleteFirstDestination();
void clear_orders();


#endif
