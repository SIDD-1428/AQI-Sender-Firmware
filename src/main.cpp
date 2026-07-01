#include <Arduino.h>
#include <Wire.h>

#include "config/config.h"
#include "utils/log.h"

#include "managers/sensorManager.h"
#include "communication/packetBuilder.h"
#include "communication/loraManager.h"
#include "models/environmentalData.h"

// Global Objects
SensorManager sensorManager;
PacketBuilder packetBuilder;
LoRaManager loRaManager;
EnvironmentalData environmentalData;

// Function Prototypes
void initializeSystem();
void acquireEnvironmentalData();
void transmitEnvironmentalData();

// Setup

void setup()
{
    Serial.begin(115200);
    delay(1000);

    Log::begin();

    Log::separator();
    Log::info("System", Config::FIRMWARE_NAME);
    Log::info("Version", Config::FIRMWARE_VERSION);
    Log::separator();

    initializeSystem();
}

// Main Loop
void loop()
{
    acquireEnvironmentalData();
    transmitEnvironmentalData();
    delay(Config::SENSOR_INTERVAL);
}

// System Initialization
void initializeSystem()
{
    Log::info("System", "Initializing...");
    Log::info("System", "Initializing I2C...");
    Wire.begin(Config::I2C_SDA_PIN,Config::I2C_SCL_PIN);
    Wire.setClock(Config::I2C_CLOCK);
    Log::info("System", "I2C Ready");
    
    bool sensorsReady = sensorManager.begin();
    bool loraReady = loRaManager.begin();

    if (!sensorsReady)
    {
        Log::error("System", "Sensor initialization failed");
        while (true)
        {
            delay(1000);
        }
    }

    if (!loraReady)
    {
        Log::error("System", "LoRa initialization failed");

        while (true)
        {
            delay(1000);
        }
    }

    Log::info("System", "Initialization Complete");
}


// Read Sensors


void acquireEnvironmentalData()
{
    environmentalData.sequenceNumber++;

    if (!sensorManager.read(environmentalData))
    {
        Log::warning("System", "Sensor acquisition failed");
        return;
    }

    environmentalData.print();
}

// Packet Transmission

void transmitEnvironmentalData()
{
    String packet = packetBuilder.build(environmentalData);

    Log::info("Packet", packet);

    if (!loRaManager.send(packet))
    {
        Log::error("LoRa", "Transmission failed");
        return;
    }

    Log::info("LoRa", "Packet transmitted");

    Log::debug("RSSI", String(loRaManager.getRSSI()));

    Log::debug("SNR", String(loRaManager.getSNR()));
}