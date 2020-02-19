#include "hardware.h"
#include "elevator_state.h"

#ifndef request_handler_h
#define request_handler_h

typedef struct {
    Floor destination;
    HardwareOrder dir;
} Order;

Order destinations[HARDWARE_NUMBER_OF_FLOORS] = {{-1,1}};
Order orders[10] = { {-1, 1} };


void place_order(Order* op, ElevatorState* ep);
void destination_sort_ascending();
void destination_sort_descending();
void swap(Order *o1, Order *o2);
void fillDestination();
void deleteFirstDestination();


#endif
