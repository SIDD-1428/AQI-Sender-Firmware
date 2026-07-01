#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <Arduino.h>

#include "../models/environmentalData.h"

#include "../sensors/bme280.h"
#include "../sensors/pms7003.h"
#include "gasManager.h"

class SensorManager{
    public:
        SensorManager();
        bool begin();
        bool read(EnvironmentalData& data);
        bool isConnected() const;
        
    private:
        BME280 m_bme280;
        PMS7003 m_pms7003;
        GasManager m_gasManager;
        bool m_connected;
};

#endif
