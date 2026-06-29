#ifndef BME280_H
#define BME280_H

#include <Arduino.h>
#include <Adafruit_BME280.h>
#include "../models/environmentalData.h"

class BME280{
    public:
        BME280();
        bool begin();
        bool read(EnvironmentalData& data);
        bool isConnected() const;
    private:
        Adafruit_BME280 m_sensor;
        bool m_connected=false;
};

#endif
