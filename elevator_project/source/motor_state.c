#include "motor_state.h"
#include <time.h>

void motor_state_elevator_transition(Floor dest, Floor pos){
    int diff = dest-pos;
    if ( diff < 0 ) hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
    if ( diff > 0 ) hardware_command_movement(HARDWARE_MOVEMENT_UP);
    if ( diff == 0) hardware_command_movement(HARDWARE_MOVEMENT_STOP);
}

void motor_state_move_elevator() {
    if ( destinations[0].pos != -1 ) {
        motor_state_elevator_transition(destinations[0].pos, ELEVATOR_STATE->pos);
        if (ELEVATOR_STATE->pos == destinations[0].pos) {
            deleteFirstDestination();
        }
        //clock_t stop_time = clock();
        //while (clock() < stop_time + CLOCKS_PER_SEC*1);
    }

}
