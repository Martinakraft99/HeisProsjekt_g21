#include "motor_state.h"


void motor_state_elevator_transition(Floor dest, Floor pos) {

      int diff = dest - pos;

      if ( diff < 0 ) {
          hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
          ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_DOWN;
      }
      if ( diff > 0 ) {
          hardware_command_movement(HARDWARE_MOVEMENT_UP);
          ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_UP;
      }
      if ( diff == 0) {
        if(ELEVATOR_STATE->dir != 1){

          while(hardware_input_read_floors() == -1){
            hardware_command_movement(((ELEVATOR_STATE->dir)-2)*(-1));
            hardware_input_take_order();

          }

        }


        hardware_command_movement(HARDWARE_MOVEMENT_STOP);
        ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_STOP;

      }
}

void motor_state_move_elevator() {
    if (destinations->pos == undef)
        request_fill_destination();

    if ( destinations->pos != undef ) {
        motor_state_elevator_transition(destinations->pos, ELEVATOR_STATE->pos);

        if (ELEVATOR_STATE->pos == destinations->pos) {
            for (int i = HardwareOrderStart; i <= HardwareOrderLast; i++)
                hardware_command_order_light(ELEVATOR_STATE->pos, i, 0);
            request_delete_first_destination();
            time_wait = clock() + CLOCKS_PER_SEC * 1;
            door_door_state_machine();
        }
    }

}
