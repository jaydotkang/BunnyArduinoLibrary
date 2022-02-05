#include "BunnyTimer.h"

BunnyTimer::BunnyTimer() { }

BunnyTimer::~BunnyTimer() { }

void BunnyTimer::update() {
    _triggered = false;
    unsigned long t = millis();
    if(_expire_time >= 0 && t > _expire_time) {
        _triggered = true;
        if(_timeout_mode) {
            _expire_time = -1;
        } else {
            _expire_time = t + _millis;
        }
    }
}

void BunnyTimer::setInterval(unsigned long t_millis, bool timeout_mode) {
    _timeout_mode = timeout_mode;
    _millis = t_millis;
    _expire_time = millis() + _millis;
}

void MyTimer::setTimeout(unsigned long t_millis) {
    setInterval(t_millis, true);
}

bool BunnyTimer::triggered() {
    return _triggered;
}

void BunnyTimer::cancel() {
    _expire_time = -1;
}