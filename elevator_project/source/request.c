#include "request.h"


Order destinations[HARDWARE_NUMBER_OF_FLOORS]  = { [0 ... HARDWARE_NUMBER_OF_FLOORS-1] = {undef, HARDWARE_ORDER_INSIDE} };
Order orders[HARDWARE_NUMBER_OF_ORDER_BUTTONS] = { [0 ... HARDWARE_NUMBER_OF_ORDER_BUTTONS-1] = {undef, HARDWARE_ORDER_INSIDE} };


void request_place_order(Order* op) {
		// no elements; place
		if (destinations->pos == undef && orders->pos == undef) {
				destinations[0] = *op;
				return;
		}

		// if exist, return
		for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++)
				if (op->pos == destinations[i].pos) return;

		for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++)
				if (op->pos == orders[i].pos && op->dir == orders[i].dir) return;


		int diff = op->pos - ELEVATOR_STATE->pos;

		if (diff == 0 && ELEVATOR_STATE->dir == HARDWARE_MOVEMENT_STOP) {
				door_door_state_machine();
				return;
		}

		if (diff > 0 && ELEVATOR_STATE->dir == HARDWARE_MOVEMENT_UP && op->dir != (int)HARDWARE_MOVEMENT_DOWN) {
				for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++) {
						if (destinations[i].pos == undef) {
								destinations[i] = *op;
								request_destination_sort_ascending();
								return;
						}
				}
		}

		if (diff < 0 && ELEVATOR_STATE->dir == HARDWARE_MOVEMENT_DOWN && op->dir != (int)HARDWARE_ORDER_UP) {
				for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++) {
						if (destinations[i].pos == undef) {
								destinations[i] = *op;
								request_destination_sort_descending();
								return;
						}
				}
		}

		for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++) {
				if (orders[i].pos == undef) {
						orders[i] = *op;
						return;
				}
		}
}

void request_destination_sort_ascending() {
	for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++)
			for (int j = i+1; j < HARDWARE_NUMBER_OF_FLOORS; j++)
					if (destinations[j].pos != undef && destinations[i].pos > destinations[j].pos)
							request_swap_order(&destinations[i], &destinations[j]);
}

void request_destination_sort_descending() {
	for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++)
			for (int j = i+1; j < HARDWARE_NUMBER_OF_FLOORS; j++)
					if (destinations[j].pos != undef && destinations[i].pos < destinations[j].pos)
							request_swap_order(&destinations[i], &destinations[j]);
}

void request_swap_order(Order* o1, Order* o2) {
		Order temp = *o1;
		*o1 = *o2;
		*o2 = temp;
}

void sort_orders() {
		for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++)
		if (orders[i].pos == undef) for (int j = i+1; j < HARDWARE_NUMBER_OF_ORDER_BUTTONS; j++)
				if (orders[j].pos != undef) {
						orders[i] = orders[j];
						orders[j] = (Order){undef, HARDWARE_ORDER_INSIDE};
						break;
				}
}

void clear_orders() {
		for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++)
		orders[i] = (Order){undef, HARDWARE_MOVEMENT_STOP};
}

void clear_destinations(){
	for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++)
	destinations[i] = (Order){undef, HARDWARE_MOVEMENT_STOP};
}

void request_delete_first_destination() {
		for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++) {
				if (orders[i].pos == destinations->pos)
						orders[i] = (Order){undef, HARDWARE_ORDER_INSIDE};
		}
		sort_orders();
		for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS-1; i++) {
				destinations[i] = destinations[i+1];
		}
		destinations[HARDWARE_NUMBER_OF_FLOORS - 1] = (Order){undef, HARDWARE_ORDER_INSIDE};
}


void request_fill_destination() {
		if (orders[0].pos != undef){
			destinations[0] = orders[0];
			ELEVATOR_STATE->dir = destinations[0].dir;
		}
		Order orders_copy[HARDWARE_NUMBER_OF_ORDER_BUTTONS];
		for(int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++)
				orders_copy[i] = orders[i];
		clear_orders();
		for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++) {
				if (orders_copy[i].pos != undef) {
						request_place_order(&orders_copy[i]);
				}
		}
}
