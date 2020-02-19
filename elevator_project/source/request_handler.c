#include "request_handler.h"




void place_order(Order* op, ElevatorState* ep) {
	for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
		if (op->destination == destinations[i].destination){
			return;
		}
	}
	if (destinations[0].destination == -1 && orders[0].destination == -1) {
		destinations[0] = *op;
		return;
	}

	int diff = op->destination - ep.pos;

	if (diff > 0 && ((op->dir == HARDWARE_ORDER_UP) || (op->dir ==  HARDWARE_ORDER_INSIDE))) {
		for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
			if (destinations[i].destination == -1){
				destinations[i] = *op;
				destination_sort_ascending();
				return;
			}
		}
	}
	if (diff < 0 && ((op->dir == HARDWARE_ORDER_DOWN) || (op->dir == HARDWARE_ORDER_INSIDE))) {
		for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
			if (destinations[i].destination == -1){
				destinations[i] = *op;
				destination_sort_descending();
				return;
			}
		}
	}
	if (diff == 0 && ep->dir == HARDWARE_MOVEMENT_STOP){
		return;
	}
	for (int i = 0; i < NUMBER_OF_POSSIBLE_ORDERS; i++){
		if (orders[i].destination == -1){
			orders[i] = *op;
			return;
		}
	}
}


void destination_sort_ascending(){
	for (int i = 1; i<HARDWARE_NUMBER_OF_FLOORS; i++){
		if (destinations[i].destination>destinations[i + 1].destination&&destinations[i + 1].destination != 0){
			swap(&destinations[i], &destinations[i + 1]);
		}
	}
}

void destination_sort_descending(){
	for (int i = 1; i<HARDWARE_NUMBER_OF_FLOORS; i++){
		if (destinations[i].destination<destinations[i + 1].destination&&destinations[i + 1].destination != 0){
			swap(&destinations[i], &destinations[i + 1]);
		}
	}
}

void swap(Order *o1, Order *o2){
	Order* temp = o1;
	o1 = o2;
	o2 = temp;
}



void deleteFirstDestination() {
	for (int i = 0; i < NUMBER_OF_POSSIBLE_ORDERS; i++) {
		if (orders[i].destination == destinations[0].destination)
			orders[i] = { -1, 1 };
	}
	sort_orders();
	for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS-1; i++) {
		destination[i] = destination[i + 1];
	}
	destination[HARDWARE_NUMBER_OF_FLOORS - 1] = { -1, 1 };
}


void sort_orders() {
	for (int i = 0; i < NUMBER_OF_POSSIBLE_ORDERS; i++) 
		if (orders[i].destination == -1) for (int j = i + 1; j < NUMBER_OF_POSSIBLE_ORDERS; j++) 
				if (orders[j] != -1) {
					orders[i] = orders[j]; 
					orders[j] = { -1, 1 }; 
					break;
				}
}

void clear_orders() {
	for (int i = 0; i < NUMBER_OF_POSSIBLE_ORDERS; i++) {
		orders[i] = { -1, 1 };
	}
}

void fillDestination(ElevatorState* ep) {
	Order orders_copy = orders;
	clear_orders();
	for (int i = 0; i < NUMBER_OF_POSSIBLE_ORDERS; i++) {
		if (orders_copy[i].destination != -1) {
			place_order(&orders_copy[i], ep);
		}
	}
}