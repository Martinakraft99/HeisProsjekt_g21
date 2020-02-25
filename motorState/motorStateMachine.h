//
//  motorStateMachine.h
//  motorState
//
//  Created by Martin A Kraft on 14/02/2020.
//  Copyright © 2020 Martin A Kraft. All rights reserved.
//

#include <stdio.h>
//#include "definitions.h"

#ifndef motorStateMachine_h
#define motorStateMachine_h

//Why can't I include def?

typedef enum {first = 1, second = 2, third = 3, fourth = 4}Floor;
typedef enum {floors, btwFandS ,btwSandT ,btwtandF}Position;
typedef enum {Down = -1, Idle = 0,UP =1}Direction;
//enum Orders{DownFourth = -4, DownThird = -3, DownSecond = -2, UpFirst = 1, UpSecond = 2, UpThird3};

typedef struct Order{
    Position pos;
    Direction dir;
}Order;

Floor destinations[4];
Order orders[6];


Direction motorStateMachine(Floor dest, Position pos);
void setMotorDirection(Direction dir);
#endif /* motorStateMachine_h */
