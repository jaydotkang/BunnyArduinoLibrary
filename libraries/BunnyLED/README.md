## BunnyLED
Simple and light-weight non-blocking library for control the blinking of the LED.
### How to use
Include the library and create a BunnyLED instance.
```c++
#include "BunnyLED.hpp"

BunnyLED led;
```
Attach a pinout.
```c++
void setup() {
  led.attach(2);
}
```
Create an array.
```c++
int blinkSeq1[] = {300, 200, 300, 200, 300, 1000};
int blinkSeqLength1 = 6;
```
Call led.blink() to start blinking.
```c++
void setup() {
  blueLED.blink(blinkSeq1, blinkSeqLength1, true);
}
```
Call led.update() in the loop function.
```c++
void loop() {
  led.update();
}
```

### Example Code
This example code control the LED on pinout 2.
```c++
#include "BunnyLED.hpp"

BunnyLED blueLED;
int blinkSeq1[] = {300, 300, 300, 300, 300, 1000};
int blinkSeqLength1 = 6;

void setup() {
  blueLED.attach(2);
  blueLED.blink(blinkSeq1, blinkSeqLength1, true);
}

void loop() {
  blueLED.update();
}
```

### Notes and Warnings
Please note that the "update()" method need to be run in "loop()" function. Otherwise the callback function will not be invoked.