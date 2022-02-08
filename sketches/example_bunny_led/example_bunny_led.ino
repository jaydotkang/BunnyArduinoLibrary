/**
** \author Jian Kang
** \copyright Apache-2.0 License
** \brief Example: Blink led 
** \details A simple example to blink led three times at an interval of 300ms and then turn off for a duration of 1000ms.
**/

#include "BunnyLED.hpp"

// Create a BunnyLED instance
BunnyLED blueLED;
// An array represents the duration of the status of led (on and off alternatively)
int blinkSeq1[] = {300, 300, 300, 300, 300, 1000};
// The length of the sequance
int blinkSeqLength1 = 6;

void setup() {
  // Attach pinout
  blueLED.attach(2);
  // Blink
  blueLED.blink(blinkSeq1, blinkSeqLength1, true);
}

void loop() {
  // Update led
  blueLED.update();
}
