/**
** \author Jian Kang
** \copyright Apache-2.0 License
** \brief BunnyTimer library 
** \details BunnyTimer library 
**/

#include "BunnyTimer.hpp"

#define MAX_MILLIS 4294967295 // The maximum value of millis()

// Construct the timer
BunnyTimer::BunnyTimer() {
    _timeoutMillis = 0;
    _lastTimestamp = 0;
    _callback = NULL;
}

// Destruct the timer
BunnyTimer::~BunnyTimer() { }

// Update the timer, invoke "_callback" function when the timer expires
void BunnyTimer::update() {
    if(_timeoutMillis > 0) {
        unsigned long currentTimestamp = millis();
        unsigned long pastMillis = currentTimestamp - _lastTimestamp;

        // Calculate the correct time when rollover happen
        if(currentTimestamp < _lastTimestamp) {
            pastMillis = MAX_MILLIS - _lastTimestamp + currentTimestamp + 1;
        }

        // Timer expires
        if(pastMillis >= _timeoutMillis) {
            // Invoke callback function
            if(_callback != NULL) {
                _callback();
            }
            // Repeat or stop
            if(_repeat) {
                _lastTimestamp = currentTimestamp;
            } else {
                _timeoutMillis = 0;
            }
        }
    } 
}

// Set timeout, the 'callback' function will be invoked after 'timeoutMillis'
void BunnyTimer::setTimeout(unsigned long timeoutMillis, f_void_t callback) {
    _timeoutMillis = timeoutMillis;
    _callback = callback;
    _repeat = false;
    _lastTimestamp = millis();
}

// Set interval, the 'callback' function will be invoked every 'timeoutMillis'
void BunnyTimer::setInterval(unsigned long timeoutMillis, f_void_t callback) {
    _timeoutMillis = timeoutMillis;
    _callback = callback;
    _repeat = true;
    _lastTimestamp = millis();
}

// Cancel the timer
void BunnyTimer::cancel() {
    _timeoutMillis = 0;
}