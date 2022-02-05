#ifndef _BUNNY_TIMER_H__
#define _BUNNY_TIMER_H__

#include "Arduino.h"

typedef void (*f_int_t) ();

class BunnyTimer {
private:
    unsigned long _millis;
    unsigned long _expire_time = -1;
    bool _timeout_mode = false;
    bool _triggered = false;
    f_int_t _callback = NULL;
    
public:
    BunnyTimer();
    ~ BunnyTimer();
    void update();
    void setInterval(unsigned long t_millis);
    void setTimeout(unsigned long t_millis);
    void setCallback(f_int_t);
    bool triggered();
    void cancel();
};

#endif