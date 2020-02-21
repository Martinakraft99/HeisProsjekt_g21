/**
* @file
* @brief Main.
*
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

#include "elevator_state.h"
#include "hardware.h"
#include "hardware_input.h"
#include "motor_state.h"
#include "start_system.h"
#include "request.h"


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
    if (( check_floor != undef) && (check_floor != ELEVATOR_STATE->pos) ) {

        printf("\nFloor %d \nDirection: %d", check_floor+1,((ELEVATOR_STATE->dir)-1)*(-1));
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
}



void stop_elevator(){

  while(hardware_read_stop_signal()){

    hardware_command_stop_light(hardware_read_stop_signal());

    hardware_command_movement(HARDWARE_MOVEMENT_STOP);

    clear_orders();
    clear_destinations();

  }
  hardware_command_stop_light(hardware_read_stop_signal());
}

void run_elevator_syst(){

  while (!hardware_read_stop_signal()) {

        print_operating_info();

        elevator_state_update_pos();

        print_operating_info();


        elevator_state_update_floor_light();
        hardware_input_take_order();

        if (clock() > time_wait) {
            hardware_command_door_open(0);
            motor_state_move_elevator();
        }
  }
  stop_elevator();

  clear_all_order_lights();

}

int main() {

    start_system();

    while(1){
    run_elevator_syst();

    printf("Stopped\n");
    }
    return 0;
}
