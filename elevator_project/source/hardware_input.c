#include "hardware_input.h"
#include <stdio.h>
#include "request_handler.h"


int readFloors(){
    for(int i=0; i<4; i++){
        if(hardware_read_floor_sensor(i)==1){
            return i;
        }
    }
    return -1;
}

void takeOrder(ElevatorState* ep){
    for(int i = 0; i< HARDWARE_NUMBER_OF_FLOORS; i++){
        for(int j = 0; j<3;j++){
            if(hardware_read_order(i,j)==1){
                Order op = {i, j};
				place_order(&op, ep);
            }
        }
    }
}
