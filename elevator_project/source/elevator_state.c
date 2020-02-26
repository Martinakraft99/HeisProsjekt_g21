#include "elevator_state.h"

Elevator* ELEVATOR_STATE = &(Elevator){undef, HARDWARE_MOVEMENT_STOP};

void elevator_state_initialize(){
    ELEVATOR_STATE->pos = elevator_state_go_to_defined_pos();
    ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_STOP;
}

void elevator_state_update_pos(){
    if (hardware_input_read_floors() != undef) {
        ELEVATOR_STATE->pos = hardware_input_read_floors();
        hardware_command_floor_indicator_on(ELEVATOR_STATE->pos);
    }
}

int elevator_state_go_to_defined_pos(){
	if (hardware_input_read_floors() == undef)
        hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
    
    while (hardware_input_read_floors() == undef);

    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    return hardware_input_read_floors();
}