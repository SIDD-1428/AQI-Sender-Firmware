#include <Arduino.h>

#include "config/config.h"
#include "config/constants.h"
#include "config/build.h"

#include "utils/log.h"
#include "core/scheduler.h"

Scheduler scheduler;

//--------------------------------------------------
// Tasks
//--------------------------------------------------

void sensorTask()
{
    Log::info("Task", "Reading Sensors");
}

void loraTask()
{
    Log::info("Task", "Sending LoRa Packet");
}

void heartbeatTask()
{
    Log::info("Task", "Heartbeat");
}

//--------------------------------------------------
// Setup
//--------------------------------------------------

void setup()
{
    Log::begin();

    Log::info("System", "Boot Complete");

    scheduler.begin();

    scheduler.addTask(
        "Sensors",
        5000,
        sensorTask
    );

    scheduler.addTask(
        "LoRa",
        10000,
        loraTask
    );

    scheduler.addTask(
        "Heartbeat",
        1000,
        heartbeatTask
    );

    Log::info("System", "Scheduler Started");
}

//--------------------------------------------------
// Loop
//--------------------------------------------------

void loop()
{
    scheduler.update();
}