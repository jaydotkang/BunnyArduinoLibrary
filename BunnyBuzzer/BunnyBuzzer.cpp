#include "BunnyBuzzer.hpp"

#define MAX_MILLIS 4294967295

int BunnyBuzzer::alpha[84] = {65, 69, 73, 77, 82, 87, 92, 98, 103, 110, 116, 123,
                              130, 138, 146, 155, 164, 174, 185, 196, 207, 220, 233, 246,
                              261, 277, 293, 311, 330, 349, 370, 392, 415, 440, 466, 494,
                              523, 554, 587, 622, 659, 699, 740, 784, 831, 880, 932, 988,
                              1047, 1109, 1175, 1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976,
                              2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951,
                              4186, 4435, 4699, 4978, 5274, 5588, 5920, 6272, 6645, 7040, 7459, 7902};

BunnyBuzzer::BunnyBuzzer()
{
    tones = NULL;
    duration = NULL;
    n = 0;
    cntLoop = 0;
    index = 0;
    lastMillis = 0;
}

void BunnyBuzzer::attach(uint8_t _pin)
{
    pin = _pin;
    //pinMode(pin, OUTPUT);
}

void BunnyBuzzer::loop()
{
    if (tones != NULL && n > 0 && cntLoop != 0)
    {
        uint32_t currentMillis = millis();
        uint32_t currentDuration = 0;
        if (currentMillis >= lastMillis)
        {
            currentDuration = currentMillis - lastMillis;
        }
        else
        {
            currentDuration = MAX_MILLIS - lastMillis + currentMillis;
        }
        int d = duration[index];
        if(d < 0) d = -d;
        if (currentDuration > d)
        {
            index += 1;
            if (index >= n)
            {
                if (cntLoop > 0)
                    cntLoop--;
                index = 0;
            }
            lastMillis = currentMillis;
        }
        if (cntLoop != 0)
        {
            if (tones[index] < 0 || tones[index] >= 84)
            {
                noTone(pin);
            }
            else
            {
                int alpha1 = alpha[tones[index]];
                if(duration[index] >= 0) {
                    tone(pin, alpha1);
                } else {
                    int alpha2;
                    alpha2 = alpha[tones[(index+1)%n]];
                    double p = currentDuration * 1.0 / d;
                    int a = (alpha1 * (1-p) + alpha2 * p);
                    tone(pin, a);
                }
            }
        }
    }
    else
    {
        noTone(pin);
        pinMode(pin, INPUT);
    }
}

void BunnyBuzzer::play(int *_tones, int *_duration, int _n, int _cntLoop)
{
    pinMode(pin, OUTPUT);
    index = 0;
    lastMillis = millis();
    tones = _tones;
    duration = _duration;
    n = _n;
    cntLoop = _cntLoop;
}

void BunnyBuzzer::stop()
{
    
    cntLoop = 0;
}
