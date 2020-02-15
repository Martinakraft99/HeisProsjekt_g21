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
            if(hardware_read_order(i,j)==1){
                struct Order o = {i,j};
                struct Order* op = &o;
                return op;
            }
        }
    }
    return NULL;
}



void placeOrder(struct Order* op, struct elevator_state * ep){
    if(op->dir=0){
        switch (ep->dir){
            case -1:
                if(op->destination>=ep->pos){
                    for(int i = 0; i<11; i++){
                        if(orders[i].destination==0){
                            orders[i]=*op;
                        }
                    }
                }
                else{
                    for(int i = 0; i<4;i++){
                        if(destinations[i].destination==0){
                            destinations[i] = *op;
                        }
                    }
                }
                break;
            case 1:
                if(op->destination<=ep->pos){
                    for(int i = 0; i<11; i++){
                        if(orders[i].destination==0){
                            orders[i]=*op;
                        }
                    }
                }
                else{
                    for(int i = 0; i<4;i++){
                        if(destinations[i].destination==0){
                            destinations[i] = *op;
                        }
                    }
                }
                break;
            case 0:
                if(destinations[0].destination==0){
                    destinations[0] = *op;
                }
                else{
                    for(int i = 0; i<11; i++){
                        if(orders[i].destination==0){
                            orders[i]=*op;
                        }
                    }
                }
                break;
}
}
    else if(op->dir==-1){
        switch (ep->dir) {
            case 1:
                for(int i = 0; i<11; i++){
                    if(orders[i].destination==0){
                        orders[i]=*op;
                    }
                }
                break;
            case 0:
                if(destinations[0].destination==0){
                    destinations[0] = *op;
                }
                else{
                    for(int i = 0; i<11; i++){
                        if(orders[i].destination==0){
                            orders[i]=*op;
                        }
                    }
                }
                break;
            case -1:
                for(int i = 0; i<4;i++){
                    if(destinations[i].destination == 0){
                        destinations[i]=*op;
                    }
                }
        }
    }
    else{
        switch (ep->dir) {
            case -1:
                for(int i = 0; i<11; i++){
                    if(orders[i].destination==0){
                        orders[i]=*op;
                    }
                }
                break;
            case 0:
                if(destinations[0].destination==0){
                    destinations[0] = *op;
                }
                else{
                    for(int i = 0; i<11; i++){
                        if(orders[i].destination==0){
                            orders[i]=*op;
                        }
                    }
                }
                break;
            case 1:
                for(int i = 0; i<4;i++){
                    if(destinations[i].destination == 0){
                        destinations[i]=*op;
                    }
                }
        }
    }
}


void destination_sort_ascending(){
    for(int i = 1; i<3;i++){
        if(destinations[i].destination>destinations[i+1].destination&&destinations[i+1].destination!=0){
            swap(&destinations[i], &destinations[i+1]);
        }
    }
}

void destination_sort_decending(){
    for(int i = 1; i<3;i++){
        if(destinations[i].destination<destinations[i+1].destination&&destinations[i+1].destination!=0){
            swap(&destinations[i], &destinations[i+1]);
        }
    }
}

void swap(Order *o1, Order *o2){
    Order* temp = o1;
    o1 = o2;
    o2 = temp;
}


void test(){
    Order o1 = {2,0};
    Order o2 = {3,-1};
    Order o3 = {2,0};
    elevator_state e1 = {1,1};
    
    placeOrder(&o1, &e1);
    update_elevator_state(&e1);
    placeOrder(&o2, &e1);
    placeOrder(&o3, &e1);
}
