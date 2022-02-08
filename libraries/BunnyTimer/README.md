## BunnyTimer
Simple and light-weight non-blocking timer library for calling functions in / every specified units of time.
### How to use
Include the library and create a BunnyTimer instance.
```c++
#include "BunnyTimer.hpp"

BunnyTimer timer;
```
Call timer.update() in the loop function.
```c++
void loop() {
  timer.update();
}
```
Make a function to call when the timer expires.
```c++
void function_to_call() {
    Serial.print("Time: ");
    Serial.println(millis());
}
```
Call the function in 1000 milliseconds.
```c++
timer.setTimeout(1000, function_to_call);
```
Call the function every 1000 milliseconds.
```c++
timer.setInterval(1000, function_to_call);
```
Test if the timer has been triggered.
```c++
bool triggered = timer.triggered();
```
Cancel the timer.
```c++
timer.cancle();
```

### Example Code
This example code prints on the serial port the number of milliseconds since the Arduino board started every 1000 milliseconds.
```c++
#include "BunnyTimer.hpp"

BunnyTimer reportTimer;

void report() {
    Serial.print("Time: ");
    Serial.println(millis());
}

void setup() {
  Serial.begin(9600);
  reportTimer.setInterval(1000, report);
}

void loop() {
  reportTimer.update();
}
```

This example code show another way to use the BunnyTimer library by using timer.triggered() instead of callback function.
```c++
#include "BunnyTimer.hpp"

BunnyTimer reportTimer;

void report() {
    Serial.print("Time: ");
    Serial.println(millis());
}

void setup() {
  Serial.begin(9600);
  reportTimer.setInterval(1000);
}

void loop() {
  if(reportTimer.triggered()) {
    report();
  }
  reportTimer.update();
}
```
### Notes and Warnings
Please note that the "update()" method need to be run in "loop()" function. Otherwise the callback function will not be invoked.