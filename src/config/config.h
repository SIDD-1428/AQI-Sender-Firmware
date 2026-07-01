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

    // I2C Bus
    constexpr uint8_t I2C_SDA_PIN = 33;
    constexpr uint8_t I2C_SCL_PIN = 34;
    constexpr uint32_t I2C_CLOCK  = 400000;

    // BME280
    constexpr uint8_t BME280_I2C_ADDRESS = 0x76;

    // ADS1115
    constexpr uint8_t ADS1115_I2C_ADDRESS = 0x48;
    // Gain = GAIN_ONE (±4.096V)
    // Resolution = 0.125 mV per bit
    constexpr float ADS1115_LSB_SIZE = 0.125f;

    // PMS7003 UART
    constexpr uint8_t PMS7003_RX_PIN = 35;
    constexpr uint8_t PMS7003_TX_PIN = 36;
    constexpr uint32_t PMS7003_BAUD_RATE = 9600;

    //Communication
    constexpr uint8_t PROTOCOL_VERSION=1;
    constexpr uint16_t MAX_PACKET_SIZE=256;
    constexpr uint16_t LORA_MAX_PAYLOAD=255;

    //LoRa

    constexpr float LORA_FREQUENCY = 868.0;
    constexpr int8_t LORA_TX_POWER=14;
    constexpr uint8_t LORA_BANDWIDTH= 125.0;
    constexpr uint8_t LORA_SPREADING_FACTOR= 9;
    constexpr uint8_t LORA_CODING_RATE= 7;
    constexpr uint8_t LORA_PREAMBLE_LENGTH=8;
    constexpr int8_t LORA_SYNC_WORD = 0x12;
    constexpr bool LORA_ENABLE_CRC = true;
    constexpr uint32_t LORA_TX_TIMEOUT=3000;
    constexpr uint32_t LORA_RX_TIMEOUT=3000;
    
    // LRa Pins
    constexpr uint8_t LORA_NSS_PIN =8;
    constexpr uint8_t LORA_DIO1_PIN=14;
    constexpr uint8_t LORA_RST_PIN = 12;
    constexpr uint8_t LORA_BUSY_PIN = 13;
    // Timing
    constexpr uint32_t SENSOR_INTERVAL    = 5000;
    constexpr uint32_t LORA_INTERVAL      = 10000;
    constexpr uint32_t HEARTBEAT_INTERVAL = 1000;

    // Debug
    constexpr bool DEBUG_MODE = true;
}

#endif