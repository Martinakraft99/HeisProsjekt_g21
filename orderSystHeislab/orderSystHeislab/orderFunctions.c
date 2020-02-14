//
//  orderFunctions.c
//  orderSystHeislab
//
//  Created by Martin A Kraft on 12/02/2020.
//  Copyright © 2020 Martin A Kraft. All rights reserved.
//

#include "orderFunctions.h"
#include "definitions.h"
#include "hardware.h"

/*enum Direction findDirOrder(enum Order order,struct State s1){
    return sign(abs(order)-s1.pos);
}

void elevatorOrder(){
}
void floorOrder(){
    
}*/

struct Order* takeOrder(){
    for(int i = 1; i<= HARDWARE_NUMBER_OF_FLOORS; i++){
        for(int j = 1; j<=3;j++){
            if(hardware_read_ord(i,j)==1){
                struct Order o = {i,j};
                struct Order* op = &o;
                return op;
            }
        }
    }
}

void placeOrder(struct Order* op){
    
}
