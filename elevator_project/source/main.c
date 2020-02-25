/**
* @file
* @brief Main.
*
*/
#include "system_operation.h"

int main() {
  hardware_init();
  start_system();
  while(1)
    system_operation_run();
  return 0;
}
