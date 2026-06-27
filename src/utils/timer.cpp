#include "timer.h"

Timer::Timer(uint32_t interval)
    :m_interval(interval),
    m_startTime(0),
    m_running(false)

    {
    }

    void Timer::start(){
        m_startTime=millis();
        m_running=true;
    }

    void Timer::stop(){
        m_running=false;
    }

    void Timer::reset(){
        stop();
        start();
    }

    bool Timer::expired(){
        if(!m_running){
            return(false);
        }

        return (millis()-m_startTime)>=m_interval;
    }

    bool Timer::isRunning() const{
        return m_running;
    }

    uint32_t Timer::elapsedTime() const{
        if(!m_running){
            return 0;
        }
        uint32_t elapsed= millis()-m_startTime;
        if(elapsed>=m_interval){
            return 0;
        }

        return m_interval-elapsed;
    }