#ifndef ADS1115_H
#define ADS1115_H

#include <Arduino.h>
#include <Adafruit_ADS1X15.h>

class ADS1115
{
public:
    ADS1115();
    bool begin();
    int16_t readRaw(uint8_t channel);
    float readVoltage(uint8_t channel);
    bool isConnected() const;
private:
    Adafruit_ADS1115 m_ads;
    bool m_connected;
};

#endif