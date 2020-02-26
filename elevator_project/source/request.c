#include "request.h"

Order destinations[HARDWARE_NUMBER_OF_FLOORS] = {[0 ... HARDWARE_NUMBER_OF_FLOORS-1] = ORDER_UNDEF};
Order queue[HARDWARE_NUMBER_OF_ORDER_BUTTONS] = {[0 ... HARDWARE_NUMBER_OF_ORDER_BUTTONS-1] = ORDER_UNDEF};

void request_place_order(Order* op) {
	
	if(destinations->pos == undef && queue->pos == undef) {
		destinations[0] = *op;
		return;
	}
	
	if (order_already_handled(op))
		return;

	int diff = op->pos - ELEVATOR_STATE->pos;

	if(diff == 0 && ELEVATOR_STATE->dir == HARDWARE_MOVEMENT_STOP) {
		return;
	}
	if(diff > 0 && ELEVATOR_STATE->dir == HARDWARE_MOVEMENT_UP && op->dir != (int)HARDWARE_MOVEMENT_DOWN) {
		for(int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++)
			if(destinations[i].pos == undef) {
				destinations[i] = *op;
				orders_sort_pos(destinations, HARDWARE_NUMBER_OF_FLOORS, ascending);
				return;
			}
	}
	if (diff < 0 && ELEVATOR_STATE->dir == HARDWARE_MOVEMENT_DOWN && op->dir != (int)HARDWARE_MOVEMENT_UP) {
		for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++)
			if (destinations[i].pos == undef) {
				destinations[i] = *op;
				orders_sort_pos(destinations, HARDWARE_NUMBER_OF_FLOORS, descending);
				return;
			}
	}
	for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++)
		if (queue[i].pos == undef) {
			queue[i] = *op;
			return;
		}
}

void request_delete_current_destination() {
	for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++)
		if (queue[i].pos == destinations->pos)
			queue[i] = (Order)ORDER_UNDEF;
	orders_sort();
	for(int i = 0; i < HARDWARE_NUMBER_OF_FLOORS - 1; i++)
		destinations[i] = destinations[i+1];
	destinations[HARDWARE_NUMBER_OF_FLOORS-1] = (Order)ORDER_UNDEF;
}

void request_fill_destinations_from_queue() {
	if (queue->pos != undef) {
		destinations[0] = queue[0];
		int diff = destinations->pos - ELEVATOR_STATE->pos;
		if (diff < 0) ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_DOWN;
		if (diff > 0) ELEVATOR_STATE->dir = HARDWARE_MOVEMENT_UP;
	}

	Order queue_temp[HARDWARE_NUMBER_OF_ORDER_BUTTONS] = {[0 ... HARDWARE_NUMBER_OF_ORDER_BUTTONS-1] = ORDER_UNDEF};

	for(int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++)
		swap_order(&queue_temp[i], &queue[i]);

	for(int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++)
		if (queue_temp[i].pos != undef)
			request_place_order(&queue_temp[i]);
}

void request_clear_orders() {
	orders_clear(destinations, (int)HARDWARE_NUMBER_OF_FLOORS);
	orders_clear(queue, (int)HARDWARE_NUMBER_OF_ORDER_BUTTONS);
}

int order_already_handled(Order *op) {
	for(int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++)
		if(op->pos == destinations[i].pos)
			return 1;

	for(int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++)
		if(op->pos == queue[i].pos && op->dir == queue[i].dir)
			return 1;
	return 0;
}

void orders_sort_pos(Order *arr, int i_max, SortMode S) {
	for (int i = 0; i < i_max; i++)
		for (int j = i+1; j < i_max; j++)
			if (arr[j].pos != undef && arr[i].pos*S > arr[j].pos*S)
				swap_order(&arr[i], &arr[j]);
}

void swap_order(Order* o1, Order* o2) {
		Order temp = *o1;
		*o1 = *o2;
		*o2 = temp;
}

void orders_sort() {
	for (int i = 0; i < HARDWARE_NUMBER_OF_ORDER_BUTTONS; i++)
		if (queue[i].pos == undef)
			for (int j = i+1; j < HARDWARE_NUMBER_OF_ORDER_BUTTONS; j++)
				if (queue[j].pos != undef) {
					queue[i] = queue[j];
					queue[j] = (Order)ORDER_UNDEF;
					break;
				}
}


void orders_clear(Order *arr, int i_max) {
	for(int i = 0; i < i_max; i++)
		arr[i] = (Order)ORDER_UNDEF;
}
