#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "start_system.h"
#include "hardware_input.h"
#include "hardware.h"
#include "elevator_state.h"



int go_to_defined_pos(){
    while (readFloors() == 0) {
        hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
    }
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    return readFloors();
}

/*void update_elevator_state(ElevatorState* ep){
    ep->pos = destinations[0].destination;
    if(destinations[1].destination==0){
        ep->dir = 0;
    }
    else{
        ep->dir = destinations[1].destination - destinations[0].destination;
    }
}
*/

void initialize_elevator_state(ElevatorState* ep){
    ep->dir = 0;
    ep->pos = go_to_defined_pos();
    return;
}
