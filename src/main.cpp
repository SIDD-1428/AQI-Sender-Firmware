#include <Arduino.h>
#include <Wire.h>
#include "config/config.h"
#include "utils/log.h"
#include "models/environmentalData.h"
#include "sensors/bme280.h"

EnvironmentalData environment;
BME280 bme;

void setup(){
    Log::begin();
    Log::info("System","Testing BME280 Driver");
    Wire.begin(33,34);
    if(!bme.begin()){
        Log::error("System","BME280 initialization failed");
        return;
    }
    Log::info("System","BME280 initialized successfully");
}

void loop(){
    environment.nodeID= Config::NODE_ID;
    environment.sequenceNumber++;
    environment.uptime=millis();

    if(bme.read(environment)){
        environment.print();
    }

    delay(5000);
}