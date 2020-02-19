#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#include "hardware.h"
#include "hardware_input.h"
#include "elevator_state.h"
#include "start_system.h"
#include "control_signals.h"
#include "request_handler.h"
#include "motor_state.h"

static void clear_all_order_lights() {
    HardwareOrder order_types[3] = { HARDWARE_ORDER_UP, HARDWARE_ORDER_INSIDE, HARDWARE_ORDER_DOWN };

    for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
        for(int i = 0; i < 3; i++){
            HardwareOrder type = order_types[i];
            hardware_command_order_light(f, type, 0);
        }
    }
}

void printOperatingInfo(ElevatorState* ep){
  int check_floor = readFloors();
  if (( check_floor != -1) && (check_floor != ep1->pos) ) {
    printf("Floor %d:\nDestination: ", check_floor+1);
    for(int i = 0; i< HARDWARE_NUMBER_OF_FLOORS;i++){
      printf("%d ", destinations[i].destination+1);
    }
    printf("\nOrders: ");
    for(int i = 0; i< NUMBER_OF_POSSIBLE_ORDERS;i++){
      printf("%d ", orders[i].destination+1);
    }
    printf("\n");
  }
}


int main() {

    start_system();

    while (!hardware_read_stop_signal()){

      printOperatingInfo(ep1);

      update_elevator_pos();

      if (ep1->pos != -1) hardware_command_floor_indicator_on(ep1->pos);

      takeOrder(ep1);

      move_elevator();

      if(destinations[0].destination == -1){
        fillDestination(ep1);
      }
    }

    hardware_command_movement(HARDWARE_MOVEMENT_STOP);

    clear_all_order_lights();

    return 0;
}
