#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
#include <Arduino.h>

enum class SystemState
{
    BOOT, SELF_TEST, WARMUP, NORMAL, DEGRADED, ERROR
};

class StateMachine
{
    public:
        StateMachine();
        void begin();
        void transitionTo(SystemState newState);
        SystemState currentState() const;
        SystemState previousState() const;
        bool is(SystemState state)const;
        const char* stateName(SystemState state) const;

    private:
        SystemState m_currentState;
        SystemState m_previousState;
};

#endif