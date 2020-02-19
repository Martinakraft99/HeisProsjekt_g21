#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "start_system.h"
#include "hardware_input.h"
#include "hardware.h"
#include "elevator_state.h"

Order* ELEVATOR_STATE = &(Order){-1, 0};

int go_to_defined_pos(){
    while (hardware_input_read_floors() == -1)
        hardware_command_movement(HARDWARE_MOVEMENT_DOWN);

    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    return hardware_input_read_floors();
}


void update_elevator_pos(){
  if(hardware_input_read_floors() != -1){
    ELEVATOR_STATE->pos = hardware_input_read_floors();
  }
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

void initialize_elevator_state(){
    ELEVATOR_STATE->dir = 0;
    ELEVATOR_STATE->pos = go_to_defined_pos();
    return;
}

void elevator_state_update_floor_light() {
  if (ELEVATOR_STATE->pos != -1)
      hardware_command_floor_indicator_on(ELEVATOR_STATE->pos);
}
