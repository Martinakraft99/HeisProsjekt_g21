#include "motor_state.h"


void motor_state_elevator_transition(Floor dest, Floor pos) {
  int diff = dest - pos;
  if ( diff < 0 ) {
          hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
          //printf("SET DOWN\n");
          ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_DOWN;
      }
  if ( diff > 0 ) {
          hardware_command_movement(HARDWARE_MOVEMENT_UP);
          //printf("SET UP\n");
          ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_UP;
      }
  if (diff == 0) {
    while(hardware_input_read_floors() == undef) {
      hardware_command_movement(((ELEVATOR_STATE->dir)-2)*(-1));
      hardware_input_take_order();
      if (hardware_read_stop_signal()){
        stop_elevator();
        return;
        }
      }
      hardware_command_movement(HARDWARE_MOVEMENT_STOP);
      ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_STOP;
      hardware_command_door_open(1);
      print_operating_info();
    }
}

void motor_state_move_elevator() {
  if (destinations->pos == undef)
    request_fill_destinations_from_queue();
  if (destinations->pos != undef) {
    elevator_state_update_pos();
    motor_state_elevator_transition(destinations->pos, ELEVATOR_STATE->pos);
    if (ELEVATOR_STATE->pos == destinations->pos) {
      for (int i = HardwareOrderStart; i <= HardwareOrderLast; i++)
        hardware_command_order_light(ELEVATOR_STATE->pos, i, 0);
      request_delete_current_destination();
      time_wait = clock() + CLOCKS_PER_SEC * IDLE_TIME;
    }
  }
}
