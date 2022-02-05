#ifndef _BUNNY_BUZZER_HPP_
#define _BUNNY_BUZZER_HPP_

#include "Arduino.h"

class BunnyBuzzer
{
private:
    uint8_t pin; // unsigned 8 bits integer
    int *tones;
    int *duration;
    int n;
    int cntLoop;
    int index;
    uint32_t lastMillis;

public:
    BunnyBuzzer();
    static int alpha[84];
    void attach(uint8_t);
    void loop();
    void play(int *, int *, int, int);
    void stop();
};

#endif
