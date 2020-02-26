#include "start_system.h"



void sigint_handler(int sig) {
    (void)(sig);
    printf("Terminating elevator\n");
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    exit(0);
}

void start_system() {
    int error = hardware_init();

    if (error != 0) {
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }
    signal(SIGINT, sigint_handler);

    printf("\n=== Running elevator program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    elevator_state_initialize();
}
