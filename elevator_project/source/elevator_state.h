/**
 * @file
 * @brief State machine.
 *
 */
#include "hardware.h"

#ifndef elevator_state_h
#define elevator_state_h

/**
* @brief
*/

typedef enum {
  undef = -1, first, second, third, fourth
} Floor;

/**
 * @brief
 */
 typedef struct{
     Floor pos;
     HardwareMovement dir;
 } ElevatorState;

 ElevatorState e1;
 ElevatorState* ep1;



/**
* @brief Elevator goes down if not in defined state.
* @return floor.
*/
 int go_to_defined_pos();

/**
* @brief
*/
void initialize_elevator_state(ElevatorState* ep);

/**
* @brief
*/
void update_elevator_pos();


#endif
