#include "BunnyTimer.hpp"

BunnyTimer timer;

int led_pin = 2;
bool led_on = false;

// Callback function
void blinkLED() {
  digitalWrite(led_pin, led_on ? HIGH : LOW);
  led_on = !led_on;
}

void setup() {
  // Set led_pin as OUTPUT
  pinMode(led_pin, OUTPUT);
  // Blink led every 1000 ms
  timer.setInterval(1000, blinkLED);
}

void loop() {
  // Update timer
  timer.update();
}
