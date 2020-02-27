#include "motor_state.h"

const int IDLE_TIME = 1;

/* module functions */

void motor_state_elevator_transition() {
  int diff = destinations->pos - ELEVATOR_STATE->pos;

  if (diff < 0) {
          hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
          ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_DOWN;     
      }
  if (diff > 0) {
          hardware_command_movement(HARDWARE_MOVEMENT_UP);
          ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_UP;
  }
  if (diff == 0) {
    if (hardware_input_read_floors() == undef) {
    	if (ELEVATOR_STATE->dir == HARDWARE_MOVEMENT_UP) {
    		hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
        	ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_DOWN;
    		++ELEVATOR_STATE->pos;
    	} else
    	if (ELEVATOR_STATE->dir == HARDWARE_MOVEMENT_DOWN) {
    		hardware_command_movement(HARDWARE_MOVEMENT_UP);
			ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_UP;
    		--ELEVATOR_STATE->pos;
   		}
    	return;
	}

    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_STOP;
	hardware_command_door_open(1);
    }
}

void motor_state_move_elevator() {
  	if (destinations->pos == undef)
    	request_fill_destinations_from_queue();

  	if (destinations->pos != undef) {
    	motor_state_elevator_transition();

    if (ELEVATOR_STATE->pos == destinations->pos) {

        if (hardware_read_order(destinations->dir, destinations->pos))
        	return;
      	for (int h = HardwareOrderStart; h <= HardwareOrderLast; h++)
        	hardware_command_order_light(ELEVATOR_STATE->pos, h, 0);

      	request_delete_current_destination();
        motor_state_time_inc();
    }
  }

}

void motor_state_time_inc() {
	time_door = clock() + CLOCKS_PER_SEC * IDLE_TIME;
}


/*
while(hardware_input_read_floors() == undef) {
      hardware_command_movement(((ELEVATOR_STATE->dir)-2)*(-1));

      hardware_input_take_order();
      if (hardware_read_stop_signal()) {
        system_operation_stop_elevator();
        return;
        }
    }*/