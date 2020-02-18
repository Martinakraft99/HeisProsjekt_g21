/**
 * @file
 * @brief State machine.
 *
 */
#include "hardware.h"

#ifndef elevator_state_h
#define elevator_state_h


typedef enum {
  first, second, third, fourth
} Floor;

typedef enum {
  floors,
} Position;


/**
 * @brief Start up of the system.
 */

 typedef struct{
     Position pos;
     HardwareMovement dir;
 } ElevatorState;



/**
* @brief Elevator goes down if not in defined state.
* @return floor.
*/
 int go_to_defined_pos();


/**
* @brief Start up of the system.
*/
//void update_elevator_state(ElevatorState* ep);



/**
* @brief Start up of the system.
*/
void initialize_elevator_state(ElevatorState* ep);



#endif
