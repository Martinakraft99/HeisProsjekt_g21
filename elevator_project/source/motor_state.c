#include "motor_state.h"

void motorStateMachine(Floor dest, Floor pos){
  int diff = dest-pos;
    if (diff < 0)
        hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
    if (diff > 0)
        hardware_command_movement(HARDWARE_MOVEMENT_UP);
    if (diff == 0)
        hardware_command_movement(HARDWARE_MOVEMENT_STOP);
}
