#include "stateMachine.h"
#include "utils/log.h"

StateMachine::StateMachine()
    :m_currentState(SystemState::BOOT),
    m_previousState(SystemState::BOOT)
{}

void StateMachine::begin(){
    Log::info("StateMachine","Initialized");
}

void StateMachine::transitionTo(SystemState newState){
    if(newState==m_currentState){
        return;
    }
    m_previousState=m_currentState;
    m_currentState=newState;

    Log::state(
        stateName(m_previousState),
        stateName(m_currentState)
    );
}

SystemState StateMachine::currentState() const{
    return m_currentState;
}

SystemState StateMachine::previousState()const{
    return m_previousState;
}

bool StateMachine::is(SystemState state) const{
    return m_currentState==state;
}

const char* StateMachine::stateName(SystemState state) const{
    switch (state){
        case SystemState::BOOT: return "BOOT";
        case SystemState::SELF_TEST: return "SELF_TEST";
        case SystemState::WARMUP: return "WARMUP";
        case SystemState::NORMAL: return "NORMAL";
        case SystemState::DEGRADED: return "DEGRADED";
        case SystemState::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}