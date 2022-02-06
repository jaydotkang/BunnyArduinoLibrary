/**
** \author Jian Kang
** \copyright Apache-2.0 License
** \brief Example: Blink led 
** \details A simple example to blink led at 1000ms interval 
**/

#include "BunnyTimer.hpp"

BunnyTimer timer;

// For NodeMCU, the pin of the built-in led (blue) is 2
int led_pin = 2;
// Set the initial status of the led to OFF
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
