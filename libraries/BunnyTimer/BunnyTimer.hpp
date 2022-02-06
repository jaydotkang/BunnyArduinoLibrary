#ifndef _BUNNY_TIMER_H__
#define _BUNNY_TIMER_H__

#include "Arduino.h"

typedef void (*f_void_t) ();
 
class BunnyTimer {
private:
    unsigned long _timeoutMillis;
    unsigned long _lastTimestamp;
    bool _timeout_mode = false;
    f_void_t _callback = NULL;
    
public:
    BunnyTimer();
    ~ BunnyTimer();
    void update();
    void setInterval(unsigned long t_millis, f_void_t);
    void setTimeout(unsigned long t_millis, f_void_t);
    void cancel();
};

#endif