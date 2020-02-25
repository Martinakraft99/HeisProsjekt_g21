#include "motor_state.h"

void motor_state_move_elevator() {
  if(destinations->pos == undef)
    request_fill_destination();

  if(destinations->pos != undef) {
    elevator_state_update_pos();

    if(!floor_transition_actuation()) {
      for(int h = HardwareOrderStart; h <= HardwareOrderLast; h++)
        hardware_command_order_light(ELEVATOR_STATE->pos, h, 0);
      request_delete_current_destination();
      motor_state_time_inc();
    }
  }
}

void motor_state_time_inc() {
    time_wait = clock() + CLOCKS_PER_SEC * IDLE_TIME;
}

int floor_transition_actuation() {
  int diff = destinations->pos - ELEVATOR_STATE->pos;

  if(!diff) {
      while(hardware_input_read_floors() == undef) {
          
          if(ELEVATOR_STATE->dir == HARDWARE_MOVEMENT_DOWN)
              hardware_command_movement(HARDWARE_MOVEMENT_UP);
          if(ELEVATOR_STATE->dir == HARDWARE_MOVEMENT_UP)
              hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
          hardware_input_take_order();
          if(hardware_read_stop_signal()) {
              stop_elevator();
              return 0;
          }
      }
      hardware_command_movement(HARDWARE_MOVEMENT_STOP);
      ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_STOP;

      hardware_command_door_open(1);
      return 0;
      //print_operating_info();
  }
  if(diff < 0) 
      ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_DOWN;
  if(diff > 0) 
      ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_UP;

  hardware_command_movement(ELEVATOR_STATE->dir);
  return 1;
}