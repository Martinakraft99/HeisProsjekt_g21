/**
 * @file
 * @brief Read hardware input.
 *
 */
 #include "elevator_state.h"
 #include "hardware.h"
 #include "request_handler.h"

 #ifndef hardware_input_h
 #define hardware_input_h




 /**
 * @brief Return floor.
 */
int readFloors();
void takeOrder(ElevatorState* ep);


#endif
