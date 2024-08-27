#include "Arduino.h"

void setup();
void loop();

extern "C" void app_main()
{
  initArduino();

  setup();
  while (true)
    loop();
}

#include "sketch.cpp"
