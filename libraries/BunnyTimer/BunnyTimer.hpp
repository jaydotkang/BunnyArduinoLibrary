#ifndef _BUNNY_TIMER_H__
#define _BUNNY_TIMER_H__

#include "Arduino.h"

class BunnyTimer {
private:
    unsigned long _millis;
    unsigned long _expire_time = -1;
    bool _timeout_mode = false;
    bool _triggered = false;
    
public:
    BunnyTimer();
    ~ BunnyTimer();
    void update();
    void setInterval(unsigned long t_millis, bool timeout_mode = false);
    void setTimeout(unsigned long t_millis);
    bool triggered();
    void cancel();
};

#endif