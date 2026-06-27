#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

namespace Config
{
    // Firmware
    constexpr const char* FIRMWARE_NAME    = "AQI Sender Firmware";
    constexpr const char* FIRMWARE_VERSION = "1.0.0";

    
    // Device
    constexpr const char* NODE_ID = "AQI001";

    // Debug
    constexpr bool DEBUG_MODE = true;
}

#endif