/**
* @file
* @brief Main.
*
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

#include "hardware.h"
#include "hardware_input.h"
#include "elevator_state.h"
#include "motor_state.h"
#include "start_system.h"
#include "request_handler.h"

static void clear_all_order_lights() {
  HardwareOrder order_types[3] = { HARDWARE_ORDER_UP, HARDWARE_ORDER_INSIDE, HARDWARE_ORDER_DOWN };

  for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
    for(int i = 0; i < 3; i++){
      HardwareOrder type = order_types[i];
      hardware_command_order_light(f, type, 0);
    }
  }
}

void print_operating_info() {
    int check_floor = hardware_input_read_floors();
    if (( check_floor != -1) && (check_floor != ELEVATOR_STATE->pos) ) {
        printf("Floor %d:\nDestination: ", check_floor+1);
        for(int i = 0; i< HARDWARE_NUMBER_OF_FLOORS;i++){
        printf("%d ", destinations[i].pos+1);
    }
    printf("\nOrders: ");
    for(int i = 0; i< HARDWARE_NUMBER_OF_ORDER_BUTTONS;i++){
        printf("%d ", orders[i].pos+1);
    }
    printf("\n");
  }
}


int main() {

    start_system();
    while ( !hardware_read_stop_signal() ){

        if ( 1 ) {

            print_operating_info();
            update_elevator_pos();
            elevator_state_update_floor_light();
            hardware_input_take_order();
            motor_state_move_elevator();

        }
        if (destinations[0].pos == -1) { fillDestination(); }
  }

  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
  clear_all_order_lights();

  return 0;
}
