#include "Arduino.h"

// Using this library as an example of including Arduino libraries.
#include <EUtil.h>

const uint8_t led_pin = 2;
bool led_state = false;
ETimer blink_timer;

void setup()
{
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT);

  blink_timer.Start(1000, false);
}

void loop()
{
    // Non blocking blink...
    if (blink_timer.HasExpire())
    {
      digitalWrite(led_pin, led_state ? LOW : HIGH);
      Serial.printf("LED STATE: %s\n", led_state ? "HIGH" : "LOW");

      led_state = !led_state;
    }

    delay(1);
}
