#include "door.h"

clock_t time_wait = 1;

void door_door_state_machine(){

	if (hardware_input_read_floors() >= 0){

	  if(ELEVATOR_STATE->dir==HARDWARE_MOVEMENT_STOP){
		  	printf("Hit");

			while (!timer(3*CLOCKS_PER_SEC)&& !hardware_read_stop_signal()){
				printf("Hit");
				hardware_command_door_open(1);
			}




	  }
		if(hardware_read_stop_signal()){

			hardware_command_door_open(1);

		}
	}
	if(hardware_read_obstruction_signal()==1){
		timer();
	}

	hardware_command_door_open(0);

}
