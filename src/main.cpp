#include <Arduino.h>
#include <Wire.h>

void setup()
{
    Serial.begin(115200);
    delay(1000);

    Wire.begin(33, 34);

    Serial.println();
    Serial.println("=================================");
    Serial.println("ADS1115 I2C Scanner");
    Serial.println("=================================");
}

void loop()
{
    Serial.println("Scanning...");

    uint8_t devices = 0;

    for (uint8_t address = 1; address < 127; address++)
    {
        Wire.beginTransmission(address);

        if (Wire.endTransmission() == 0)
        {
            Serial.print("Found device at 0x");

            if (address < 16)
                Serial.print("0");

            Serial.println(address, HEX);

            devices++;
        }
    }

    if (devices == 0)
    {
        Serial.println("No I2C devices found.");
    }

    Serial.println();
    delay(5000);
}