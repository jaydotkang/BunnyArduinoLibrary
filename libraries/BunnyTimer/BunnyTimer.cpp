#include "BunnyTimer.hpp"

#define MAX_MILLIS 4294967295 // The maximum value of millis()

BunnyTimer::BunnyTimer() {
    _timeoutMillis = 0;
    _lastTimestamp = 0;
    _callback = NULL;
}

BunnyTimer::~BunnyTimer() { }

// Update the timer, call the "_callback" function if necessary
void BunnyTimer::update() {
    if(_timeoutMillis > 0) {
        unsigned long currentTimestamp = millis();
        unsigned long pastMillis = currentTimestamp - _lastTimestamp;

        // If millis() return to zero
        if(currentTimestamp < _lastTimestamp) {
            pastMillis = MAX_MILLIS - _lastTimestamp + currentTimestamp + 1;
        }

        if(pastMillis >= _timeoutMillis) {
            if(_callback != NULL) {
                _callback();
            }
            if(_timeout_mode) {
                _timeoutMillis = 0;
            } else {
                _lastTimestamp = currentTimestamp;
            }
        }
    } 
}

// Set timeout, the 'callback' function will be called with an interval of 'timeoutMillis'
void BunnyTimer::setInterval(unsigned long timeoutMillis, f_void_t callback) {
    _timeoutMillis = timeoutMillis;
    _callback = callback;
    _timeout_mode = false;
    _lastTimestamp = millis();
}

// Set timeout, the 'callback' function will be called after 'timeoutMillis'
void BunnyTimer::setTimeout(unsigned long timeoutMillis, f_void_t callback) {
    _timeoutMillis = timeoutMillis;
    _callback = callback;
    _timeout_mode = true;
    _lastTimestamp = millis();
}

// Cancel the timer
void BunnyTimer::cancel() {
    _timeoutMillis = 0;
}