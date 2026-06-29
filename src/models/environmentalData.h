#ifndef ENVIRONMENTAL_DATA_H
#define ENVIRONMENTAL_DATA_H

#include <Arduino.h>

class EnvironmentalData{
    public:
        EnvironmentalData();

        //utility functions
        void clear();
        bool isComplete() const;
        bool isValid() const;
        void print() const;


        //metadata
        const char* nodeID;
        uint32_t sequenceNumber;
        uint32_t uptime;

        //climate 
        float temperature;
        float humidity;
        float pressure;

        //particles
        float pm1_0;
        float pm2_5;
        float pm10;

        //gases
        float ozone;
        float nitrogenDioxide;
        float carbonMonoxide;
        float ammonia;
        float sulfurDioxide;

        //status
        bool hasClimateData;
        bool hasParticulateData;
        bool hasGasData;

        //validation
        bool validated;

        //diagnositcs
        uint32_t lastUpdated;
};

#endif