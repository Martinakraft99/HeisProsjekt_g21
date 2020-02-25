#include "system_operation.h"

void run_elevator_syst() {

  while (!hardware_read_stop_signal()) {

    elevator_state_update_pos();
    elevator_state_update_floor_light();
    hardware_input_take_order();

    if(hardware_read_obstruction_signal() && clock() < time_wait && hardware_input_read_floors() != undef) {
            time_wait = clock() + CLOCKS_PER_SEC * IDLE_TIME;
    }

    if (clock() > time_wait ) {
      hardware_command_door_open(0);
      motor_state_move_elevator();
    }
  }
  printf("Stopped\n");
  stop_elevator();

}

void print_operating_info() {

        printf("\nFloor %d \nDirection: %d", hardware_input_read_floors()+1,((ELEVATOR_STATE->dir)-1)*(-1));
        printf("\nDestinations: ");
        for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++) {
            printf("%d ", destinations[i].pos+1);
        }

        printf("\nOrders: ");
        for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++) {
            printf("%d ", orders[i].pos+1);
        }
        printf("\n");
}

static void clear_all_order_lights() {
  HardwareOrder order_types[3] = { HARDWARE_ORDER_UP, HARDWARE_ORDER_INSIDE, HARDWARE_ORDER_DOWN };

  for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
    for(int i = 0; i < 3; i++){
      HardwareOrder type = order_types[i];
      hardware_command_order_light(f, type, 0);
    }
  }
}

void stop_elevator(){
  hardware_command_stop_light(1);
  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
  orders_clear();
  destinations_clear();

  if (hardware_input_read_floors() != undef)
      hardware_command_door_open(1);

  while(hardware_read_stop_signal());

  clear_all_order_lights();
  time_wait = clock() + CLOCKS_PER_SEC * IDLE_TIME;
  hardware_command_stop_light(0);
}
