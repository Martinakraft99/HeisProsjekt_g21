/**
* @file
* @brief Main.
*
*/
#include "system_operation.h"

int main() {

    start_system();
    while(1)
    	system_operation_run();

    return 0;
}
