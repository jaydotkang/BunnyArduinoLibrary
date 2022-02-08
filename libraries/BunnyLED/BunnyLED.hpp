/**
** \author Jian Kang
** \copyright Apache-2.0 License
** \brief BunnyLED library 
** \details BunnyLED library 
**/

#ifndef _BUNNY_LED_HPP__
#define _BUNNY_LED_HPP__

#include "BunnyTimer.hpp"

class BunnyLED {
private:
    int _pin;
    int* _seq;
    int _seqIndex;
    int _seqLength;
    bool _repeat;
    bool _lightOnHigh;
    BunnyTimer _timer;
    void run();

public:
    BunnyLED();
    ~ BunnyLED();
    void attach(int);
    void update();
    void blink(int*, int, bool);
};

#endif