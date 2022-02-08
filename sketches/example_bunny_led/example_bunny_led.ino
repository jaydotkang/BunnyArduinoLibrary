/**
** \author Jian Kang
** \copyright Apache-2.0 License
** \brief Example: Blink led 
** \details A simple example to blink led three times at 300ms interval and then turn off for 1000ms.
**/

#include "BunnyLED.hpp"

BunnyLED blueLED;
int blinkSeq1[] = {300, 300, 300, 300, 300, 1000};
int blinkSeqLength1 = 6;

void setup() {
  blueLED.attach(2);
  blueLED.blink(blinkSeq1, blinkSeqLength1, false);
}

void loop() {
  // Update the led
  blueLED.update();
}
