/**
* @file
* @brief Main.
*
*/

#include "system_operation.h"



int main() {

    hardware_init(); 
    
    start_system();

    while(1){

        run_elevator_syst();

    }

    return 0;
}
