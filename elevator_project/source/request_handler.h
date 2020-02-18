#include "hardware.h"
#include "elevator_state.h"

#ifndef request_handler_h
#define request_handler_h

typedef struct {
    Floor destination;
    HardwareOrder dir;
} Order;

Order destinations[HARDWARE_NUMBER_OF_FLOORS] = {{-1,1}};
//struct Order* orders[10];

#endif
