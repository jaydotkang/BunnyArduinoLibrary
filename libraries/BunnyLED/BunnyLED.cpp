/**
** \author Jian Kang
** \copyright Apache-2.0 License
** \brief BunnyLED library 
** \details BunnyLED library 
**/

#include "BunnyLED.hpp"

// Construct
BunnyLED::BunnyLED() {
    _pin = -1;
    _seq = NULL;
    _seqIndex = 0;
    _seqLength = 0;
    _repeat = true;
}


// Destruct
BunnyLED::~BunnyLED() { }

// Attach a pinout
void BunnyLED::attach(int pin) {
    _pin = pin;
    pinMode(pin, OUTPUT);
}

// Start blinking
void BunnyLED::blink(int* seq, int seqLength, bool repeat) {
    _seq = seq;
    _seqLength = seqLength;
    _repeat = repeat;
    _timer.cancel();
    run();
}

// Update
void BunnyLED::update() {
    _timer.update();
    if(_timer.triggered()) {
        run();
    }
}

// Update LED status
void BunnyLED::run() {
    if(_seq != NULL && _seqIndex < _seqLength) {
        _timer.setTimeout(_seq[_seqIndex]);
        digitalWrite(_pin, (_seqIndex%2 == 0)? LOW:HIGH);
        _seqIndex++;
        if(_repeat && _seqIndex == _seqLength) {
            _seqIndex = 0;
        }
    }
}
