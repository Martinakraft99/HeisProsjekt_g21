/**
* @file
* @brief Main.
*
*/

#include "system_operation.h"

int main() {

    hardware_init(); 
    start_system();

    run_elevator_syst();

    return 0;
}
