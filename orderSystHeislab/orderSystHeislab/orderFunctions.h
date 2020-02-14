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

Direction findDirOrder();
void floorOrder();
void elevatorOrder();
Order* takeOrder();
void destSort();
void test();

#endif /* orderFunctions_h */
