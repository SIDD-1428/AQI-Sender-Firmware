#include <Arduino.h>

#include "config/config.h"
#include "config/constants.h"
#include "config/build.h"

#include "utils/log.h"
#include "utils/timer.h"

Timer sensorTimer(5000);

void setup()
{
    Log::begin();
    Log::info("System", "Boot Complete");
    sensorTimer.start();
}

void loop()
{
    if(sensorTimer.expired()){
        Log::info("Timer","5 seconds Passed");
        sensorTimer.reset();
    }
}