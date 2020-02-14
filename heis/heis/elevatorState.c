//
//  elevatorState.c
//  heis
//
//  Created by Martin A Kraft on 14/02/2020.
//  Copyright © 2020 Martin A Kraft. All rights reserved.
//

#include "elevatorState.h"


int readFloors(){
    for(int i{1}; i<=4; i++){
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

void update elevator_state(struct elevator_state& e){
    e.pos = destinations[0.dest];
    if(destinations[1.dest]==0){
        e.dir = 0;
    }
    else{
        e.dir = destinations[1.dest] - destinations[0.dest];
    }
}
void initialize elevator_state(struct elevator_state& e){
    e.direction = 0;
    e.pos = go_to_defined_pos();
}



