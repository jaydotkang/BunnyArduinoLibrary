/**
** \author Jian Kang
** \copyright Apache-2.0 License
** \brief BunnyTimer library 
** \details BunnyTimer library 
**/

#ifndef _BUNNY_TIMER_H__
#define _BUNNY_TIMER_H__

#include "Arduino.h"

typedef void (*f_void_t) ();
 
class BunnyTimer {
private:
    unsigned long _timeoutMillis;
    unsigned long _lastTimestamp;
    bool _repeat = false;
    f_void_t _callback = NULL;
    
public:
    BunnyTimer();
    ~ BunnyTimer();
    void update();
    void setInterval(unsigned long, f_void_t);
    void setTimeout(unsigned long, f_void_t);
    void cancel();
};

#endif