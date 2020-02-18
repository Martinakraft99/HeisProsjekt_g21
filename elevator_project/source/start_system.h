/**
 * @file
 * @brief Start up progress for elevator.
 *
 */

#include "elevator_state.h"

 #ifndef start_system_h
 #define start_system_h


/**
* @brief Sigint handler.
*/
void sigint_handler(int sig);


/**
 * @brief Start up of the system.
 */
void start_system(ElevatorState* e1);

#endif
