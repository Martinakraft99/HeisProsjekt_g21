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
#include "definitions.h"


typedef struct elevator_state{
    Position pos;
    Direction dir;
}elevator_state;

int readFloors();
int go_to_defined_pos();
void update_elevator_state(struct elevator_state* ep);
void initialize_elevator_state(struct elevator_state* ep);


#endif /* elevatorState_h */
