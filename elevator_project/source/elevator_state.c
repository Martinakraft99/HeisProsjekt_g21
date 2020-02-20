#include "elevator_state.h"



Elevator* ELEVATOR_STATE = &(Elevator){undef, HARDWARE_MOVEMENT_STOP};

int elevator_state_go_to_defined_pos(){
    while (hardware_input_read_floors() == undef)
        hardware_command_movement(HARDWARE_MOVEMENT_DOWN);

    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    return hardware_input_read_floors();
}

void elevator_state_update_pos(){
    if (hardware_input_read_floors() != undef) {
        ELEVATOR_STATE->pos = hardware_input_read_floors();
    }
}

void elevator_state_initialize(){
    ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_STOP;
    ELEVATOR_STATE->pos = elevator_state_go_to_defined_pos();


    return;
}

void elevator_state_update_floor_light() {
      if (ELEVATOR_STATE->pos != undef)
          hardware_command_floor_indicator_on(ELEVATOR_STATE->pos);
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
