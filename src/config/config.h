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

    //i2c
    constexpr uint8_t BME280_I2C_ADDRESS = 0x76;
    constexpr uint8_t ADS1115_I2C_ADDRESS = 0x48;
    
    //uart
    constexpr uint8_t PMS7003_RX_PIN=35;
    constexpr uint8_t PMS7003_TX_PIN=36;
    constexpr uint8_t PMS7003_BAUD_RATE=9600;

    // Debug
    constexpr bool DEBUG_MODE = true;

    //timing
    constexpr uint32_t SENSOR_INTERVAL = 5000;
    constexpr uint32_t LORA_INTERVAL = 10000;
    constexpr uint32_t HEARTBEAT_INTERVAL = 1000;
}

#endif