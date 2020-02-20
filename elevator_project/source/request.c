#include "request.h"
#include "elevator_state.h"


Order destinations[HARDWARE_NUMBER_OF_FLOORS] = { [0 ... HARDWARE_NUMBER_OF_FLOORS-1] = {-1,1} };
Order orders[HARDWARE_NUMBER_OF_ORDER_BUTTONS] = { [0 ... HARDWARE_NUMBER_OF_ORDER_BUTTONS-1] = {-1,1} };

void place_order(Order* op) {
		if (destinations[0].pos == -1 && orders[0].pos == -1) {
				destinations[0] = *op;
				return;
		}

	for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
		if (op->pos == destinations[i].pos){
			return;
		}
	}

	int diff = op->pos - ELEVATOR_STATE->pos;

	if (diff > 0 && ((op->dir == HARDWARE_ORDER_UP) || (op->dir ==  HARDWARE_ORDER_INSIDE))) {
		for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
			if (destinations[i].pos == -1){
				destinations[i] = *op;
				destination_sort_ascending();
				return;
			}
		}
	}
	if (diff < 0 && ((op->dir == HARDWARE_ORDER_DOWN) || (op->dir == HARDWARE_ORDER_INSIDE))) {
		for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
			if (destinations[i].pos == -1){
				destinations[i] = *op;
				destination_sort_descending();
				return;
			}
		}
	}
	if (diff == 0 && (int)ELEVATOR_STATE->dir == (int)HARDWARE_MOVEMENT_STOP){
		return;
	}
	for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++){
		if (orders[i].pos == -1){
			printf("HIT");
			orders[i] = *op;
			return;
		}
	}
}

void destination_sort_ascending() {
		for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++)
				for (int j = i+1; j < HARDWARE_NUMBER_OF_FLOORS; j++)
						if (destinations[j].pos != -1 && destinations[i].pos > destinations[j].pos)
								swap(&destinations[i], &destinations[j]);
}

void destination_sort_descending() {
		for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++)
				for (int j = i+1; j < HARDWARE_NUMBER_OF_FLOORS; j++)
						if (destinations[j].pos != -1 && destinations[i].pos < destinations[j].pos)
								swap(&destinations[i], &destinations[j]);
}

void swap(Order *o1, Order *o2) {
		Order temp = *o1;
		*o1 = *o2;
		*o2 = temp;
}

void sort_orders() {
	for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++)
		if (orders[i].pos == -1) for (int j = i + 1; j < HARDWARE_NUMBER_OF_ORDER_BUTTONS; j++)
				if (orders[j].pos != -1) {
					orders[i] = orders[j];
					orders[j].pos = -1;
					orders[j].dir = 1;
					break;
				}
}

void deleteFirstDestination() {
	for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++) {
		if (orders[i].pos == destinations[0].pos){
			orders[i].pos = -1;
			orders[i].dir = 1;
		}

	}
	sort_orders();
	for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS-1; i++) {
		destinations[i] = destinations[i + 1];
	}
	destinations[HARDWARE_NUMBER_OF_FLOORS - 1].pos = -1;
	destinations[HARDWARE_NUMBER_OF_FLOORS - 1].dir = 1;
}

void clear_orders() {
	for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++) {
		orders[i].pos = -1;
		orders[i].dir = 1;
	}
}

void fillDestination() {
	Order orders_copy[HARDWARE_NUMBER_OF_ORDER_BUTTONS] = {{-1,1}};
	for(int i = 0; i< HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++){
		orders_copy[i] = orders[i];
	}
	clear_orders();
	for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++) {
		if (orders_copy[i].pos != -1) {
			place_order(&orders_copy[i]);
		}
	}
}
