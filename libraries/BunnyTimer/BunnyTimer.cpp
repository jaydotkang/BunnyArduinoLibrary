#include "BunnyTimer.hpp"

BunnyTimer::BunnyTimer() { }

BunnyTimer::~BunnyTimer() { }

void BunnyTimer::update() {
    _triggered = false;
    unsigned long currentMillis = millis();
    if(_expire_time >= 0 && currentMillis > _expire_time) {
        _triggered = true;
        if(_callback != NULL) {
            _callback();
        }
        if(_timeout_mode) {
            _expire_time = -1;
        } else {
            _expire_time = currentMillis + _millis;
        }
    }
}

void BunnyTimer::setInterval(unsigned long t_millis) {
    _timeout_mode = false;
    _millis = t_millis;
    _expire_time = millis() + _millis;
}

void BunnyTimer::setCallback(f_int_t callback) {
    _callback = callback;
}



void BunnyTimer::setTimeout(unsigned long t_millis) {
    _timeout_mode = true;
    _millis = t_millis;
    _expire_time = millis() + _millis;
}

bool BunnyTimer::triggered() {
    return _triggered;
}

void BunnyTimer::cancel() {
    _expire_time = -1;
}