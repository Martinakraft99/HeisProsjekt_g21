#include "elevator_state.h"
#include "hardware.h"
#include "hardware_input.h"

int readFloors(){
    for(int i=0; i<4; i++){
        if(hardware_read_floor_sensor(i)==1){
            return i+1;
        }
    }
    return 0;
}
