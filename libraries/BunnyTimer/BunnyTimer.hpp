/**
** \author Jian Kang
** \copyright Apache-2.0 License
** \brief BunnyTimer library 
** \details BunnyTimer library 
**/

#ifndef _BUNNY_TIMER_HPP__
#define _BUNNY_TIMER_HPP__

#include "Arduino.h"

typedef void (*f_void_t) ();
 
class BunnyTimer {
private:
    unsigned long _timeoutMillis;
    unsigned long _lastTimestamp;
    bool _repeat = false;
    f_void_t _callback = NULL;
    bool _triggered = false;
    
public:
    BunnyTimer();
    ~ BunnyTimer();
    void update();
    void setInterval(unsigned long, f_void_t callback = NULL);
    void setTimeout(unsigned long, f_void_t callback = NULL);
    void cancel();
    bool triggered();
};

#endif