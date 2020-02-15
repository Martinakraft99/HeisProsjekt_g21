//
//  elevatorState.c
//  heis
//
//  Created by Martin A Kraft on 14/02/2020.
//  Copyright © 2020 Martin A Kraft. All rights reserved.
//

#include "elevatorState.h"


int readFloors(){
    for(int i=1; i<=4; i++){
        if(hw_read_floor_sensor(i)==1){
            return i;
        }
    }
    return 0;
}

int go_to_defined_pos(){
    while (readFloors() == 0){
        hw_cmd_mov(Down);
    }
    return readFloors();
}

void update_elevator_state(struct elevator_state* ep){
    ep->pos = destinations[0].destination;
    if(destinations[1].destination==0){
        ep->dir = 0;
    }
    else{
        ep->dir = destinations[1].destination - destinations[0].destination;
    }
}
void initialize_elevator_state(struct elevator_state* ep){
    ep->dir = 0;
    ep->pos = go_to_defined_pos();
}



