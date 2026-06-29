#include <Arduino.h>

#include "config/config.h"
#include "utils/log.h"
#include "models/environmentalData.h"

EnvironmentalData data;

void setup()
{
    Log::begin();

    Log::info("System", "Testing EnvironmentalData");

    //----------------------------------------
    // Metadata
    //----------------------------------------

    data.nodeID = Config::NODE_ID;
    data.sequenceNumber = 1;
    data.uptime = millis();

    //----------------------------------------
    // Climate
    //----------------------------------------

    data.temperature = 29.4f;
    data.humidity = 71.8f;
    data.pressure = 1008.7f;

    //----------------------------------------
    // Particulates
    //----------------------------------------

    data.pm1_0 = 8.0f;
    data.pm2_5 = 13.0f;
    data.pm10 = 22.0f;

    //----------------------------------------
    // Gases
    //----------------------------------------

    data.ozone = 0.021f;
    data.sulfurDioxide = 0.004f;
    data.nitrogenDioxide = 0.011f;
    data.carbonMonoxide = 0.52f;
    data.ammonia = 0.09f;

    //----------------------------------------
    // Status
    //----------------------------------------

    data.hasClimateData = true;
    data.hasParticulateData = true;
    data.hasGasData = true;

    data.validated = true;

    data.lastUpdated = millis();

    //----------------------------------------
    // Print
    //----------------------------------------

    data.print();
}

void loop()
{
}