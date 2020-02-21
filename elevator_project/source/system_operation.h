/**
* @file
* @brief Hardware input.
*
*/
#ifndef SYSTEM_OPERATION_H
#define SYSTEM_OPERATION_H

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include "elevator_state.h"
#include "hardware.h"
#include "hardware_input.h"
#include "motor_state.h"
#include "start_system.h"
#include "request.h"

//static void clear_all_order_lights();
void print_operating_info();
void stop_elevator();
void run_elevator_syst();



#endif
