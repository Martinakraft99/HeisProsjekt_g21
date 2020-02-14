//
//  definitions.h
//  orderSystHeislab
//
//  Created by Martin A Kraft on 12/02/2020.
//  Copyright © 2020 Martin A Kraft. All rights reserved.
//

#ifndef definitions_h
#define definitions_h


enum Floor {first = 1, second = 2, third = 3, fourth = 4};
enum Position{floors, btwFandS ,btwSandT ,btwtandF};
enum Direction{Down = -1, Idle = 0,UP =1};
enum Order{DownFourth = -4, DownThird = -3, DownSecond = -2, UpFirst = 1, UpSecond = 2, UpThird3};

struct State{
    enum Position pos;
    enum Direction dir;
};

enum Floor destinations[4];
enum Order orders[6];




#endif /* definitions_h */
