#include "door.h"

clock_t time_wait = 1;


void door_door_state_machine(){

	if (hardware_input_read_floors()){
	  if(ELEVATOR_STATE->pos == destinations[0].pos){

			hardware_command_door_open(1);

	  }
		if(hardware_read_stop_signal()){

			hardware_command_door_open(1);

		}
	}
	if(hardware_read_obstruction_signal()==1){
		time_wait = clock() + CLOCKS_PER_SEC * 1;
	}

	hardware_command_door_open(0);

}
