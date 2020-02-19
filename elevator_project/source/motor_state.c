#include "motor_state.h"
#include <time.h>

void motorStateMachine(Floor dest, Floor pos){
  int diff = dest-pos;
    if (diff < 0)
        hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
    if (diff > 0)
        hardware_command_movement(HARDWARE_MOVEMENT_UP);
    if (diff == 0)
        hardware_command_movement(HARDWARE_MOVEMENT_STOP);
}


void move_elevator() {

  if( destinations[0].destination != -1 ) {
      motorStateMachine(destinations[0].destination, ep1->pos);

      if (ep1->pos == destinations[0].destination) {
          deleteFirstDestination();
          clock_t currTime = clock();
          while (clock() < currTime + 3000);
      }
  }

}
