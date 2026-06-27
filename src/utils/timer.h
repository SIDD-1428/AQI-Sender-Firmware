#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer{
    public: 
        explicit Timer(uint32_t interval);
        void start();
        void stop();
        void reset();

        bool expired();
        bool isRunning() const;

        uint32_t elapsedTime() const;
        uint32_t remainingTime() const;

    private:
        uint32_t m_interval;
        uint32_t m_startTime;
        bool m_running;
};

#endif