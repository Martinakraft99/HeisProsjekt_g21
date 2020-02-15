//
//  orderFunctions.h
//  orderSystHeislab
//
//  Created by Martin A Kraft on 12/02/2020.
//  Copyright © 2020 Martin A Kraft. All rights reserved.
//

#ifndef orderFunctions_h
#define orderFunctions_h

#include <stdio.h>
#include "definitions.h"
#include "elevatorState.h"

Direction findDirOrder();
void floorOrder();
void elevatorOrder();
Order* takeOrder();
void destSort();
void test();
void placeOrder(struct Order* op, struct elevator_state * ep);
void destination_sort_ascending();
void destination_sort_decending();
void swap(Order *o1, Order *o2);

void test();



#endif /* orderFunctions_h */
