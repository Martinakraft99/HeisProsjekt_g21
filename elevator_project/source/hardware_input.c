#include "hardware_input.h"

int hardware_input_read_floors() {
  for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++)
    if(hardware_read_floor_sensor(f)) 
        return f;
  return undef;
}

void hardware_input_take_order() {
  for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++)
    for(int h = HardwareOrderStart; h <= HardwareOrderLast; h++)
      if (hardware_read_order(f, h)) {
        hardware_command_order_light(f, h, 1);
        request_place_order(&(Order){f, h});
      }
}
