//
//  definitions.h
//  orderSystHeislab
//
//  Created by Martin A Kraft on 12/02/2020.
//  Copyright © 2020 Martin A Kraft. All rights reserved.
//

#include <stdlib.h>

#ifndef definitions_h
#define definitions_h



typedef enum {first = 1, second = 2, third = 3, fourth = 4}Floor;
typedef enum {floors, btwFandS ,btwSandT ,btwtandF}Position;
typedef enum {Down = -1, Idle = 0,UP =1}Direction;
//enum Orders{DownFourth = -4, DownThird = -3, DownSecond = -2, UpFirst = 1, UpSecond = 2, UpThird3};

struct Order{
    Floor destination;
    Direction dir;
};

Floor destinations[4];
struct Order orders[8];




#endif /* definitions_h */
