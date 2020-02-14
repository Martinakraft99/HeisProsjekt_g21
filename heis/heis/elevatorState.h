//
//  elevatorState.h
//  heis
//
//  Created by Martin A Kraft on 14/02/2020.
//  Copyright © 2020 Martin A Kraft. All rights reserved.
//

#ifndef elevatorState_h
#define elevatorState_h

#include <stdio.h>
#include "definitions"


struct elevator_State{
    Position pos;
    Direction dir;
};

int readFloors();
int go_to_defined_pos();
void update elevator_state(struct elevator_state& e);
void initialize elevator_state(struct elevator_state& e);


#endif /* elevatorState_h */
