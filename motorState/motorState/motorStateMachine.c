//
//  motorStateMachine.c
//  motorState
//
//  Created by Martin A Kraft on 14/02/2020.
//  Copyright © 2020 Martin A Kraft. All rights reserved.
//

#include "motorStateMachine.h"


Direction motorStateMachine(Floor dest, Position pos){
    if(pos == dest){
        return 0;
    }
    else{
        return (sign(pos - dest));
    }
}

void setMotorDirection(Direction dir){
    Hardware_Command_Movement(dir);
}
