#include <Arduino.h>

#include "config/config.h"
#include "config/constants.h"
#include "config/build.h"

#include "utils/log.h"
#include "core/stateMachine.h"

StateMachine stateMachine;

void setup()
{
    Log::begin();
    Log::info("System", "Boot Complete");
    stateMachine.begin();
    delay(1000);
    stateMachine.transitionTo(SystemState::SELF_TEST);
    delay(1000);
    stateMachine.transitionTo(SystemState::WARMUP);
    delay(1000);
    stateMachine.transitionTo(SystemState::NORMAL);
}

void loop()
{}