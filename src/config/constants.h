#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Arduino.h>

namespace Constants
{
    //Serial
        constexpr uint32_t SERIAL_BAUD =115200;

    //Timing
        constexpr uint32_t SENSOR_READ_INTERVAL_MS=60000;
        constexpr uint32_t MQ_WARMUP_TIME_MS=300000;

    //Communication
        constexpr uint8_t MAX_LORA_RETRIES =3;
    
    //validation
        constexpr uint8_t MAX_SENSOR_ERRORS=5;

    //bATTERY
        constexpr float LOW_BATTERY_VOLTAGE=11.50f;
}

#endif