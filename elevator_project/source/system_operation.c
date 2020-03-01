#include "system_operation.h"

/* module functions */

void system_operation_run() {

  while (!hardware_read_stop_signal()) {

    elevator_state_update_pos();
    hardware_input_take_order();

    if(clock() < time_door && hardware_read_obstruction_signal() && hardware_input_read_floors() != undef)
      motor_state_time_inc();

    if (clock() > time_door ) {
      hardware_command_door_open(0);
      motor_state_move_elevator();
    }
  } system_operation_stop_elevator();
}

void system_operation_stop_elevator() {
  hardware_command_stop_light(1);
  hardware_command_movement(HARDWARE_MOVEMENT_STOP);

  if (hardware_input_read_floors() != undef)
      hardware_command_door_open(1);

  while(hardware_read_stop_signal());
  print_operating_info();
  request_clear_orders();

  clear_all_order_lights();
  motor_state_time_inc();

  hardware_command_stop_light(0);
}

/* help functions */

void print_operating_info() {
        printf("\nFloor %d \nDirection: %d", ELEVATOR_STATE->pos+1,((ELEVATOR_STATE->dir)-1)*(-1));
        printf("\nDestinations: ");
        for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++) {
            printf("%d ", destinations[i].pos+1);
        }
        printf("\nOrders: ");
        for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++) {
            printf("%d ", queue[i].pos+1);
        }
        printf("\n");
}

void clear_all_order_lights() {
  HardwareOrder order_types[3] = { HARDWARE_ORDER_UP, HARDWARE_ORDER_INSIDE, HARDWARE_ORDER_DOWN };

  for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
    for(int i = 0; i < 3; i++){
      HardwareOrder type = order_types[i];
      hardware_command_order_light(f, type, 0);
    }
  }
}
