## BunnyTimer
An Arduino library to support timer functionalities.
### Description

### Example Code
This example code prints on the serial port the number of milliseconds since the Arduino board started every 1000 milliseconds.
```c++
#include "BunnyTimer.hpp"

BunnyTimer timer1;

void report() {
    Serial.print("Time: ");
    Serial.println(millis());
}

void setup() {
  Serial.begin(9600);
  timer1.setInterval(1000, report);
}

void loop() {
  timer1.update();
}
```