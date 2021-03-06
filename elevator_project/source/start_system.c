/**
* @file
* @brief Source code start_system module.
*/
#include "start_system.h"

/**
* @brief Intern module function. Sigint handler.
*/
static void sigint_handler(int sig);

/* module functions */

void start_system() {
    int error = hardware_init();

    if (error != 0) {
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }
    signal(SIGINT, sigint_handler);

    printf("\n=== Running elevator program (Tufte and Kraft) ===\n");
    elevator_state_initialize();
}

/* help functions */

static void sigint_handler(int sig) {
    (void)(sig);
    printf("Terminating elevator\n");
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    exit(0);
}
