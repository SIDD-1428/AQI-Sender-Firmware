#ifndef GAS_MANAGER_H
#define GAS_MANAGER_H

#include <Arduino.h>

#include "../models/environmentalData.h"
#include "../sensors/ads1115.h"

class GasManager
{
public:

    GasManager();

    bool begin();

    bool read(EnvironmentalData& data);

    bool isConnected() const;

private:

    //----------------------------------------
    // Individual Gas Readers
    //----------------------------------------

    void readOzone(EnvironmentalData& data);

    void readNitrogenDioxide(EnvironmentalData& data);

    void readCarbonMonoxide(EnvironmentalData& data);

    void readAmmonia(EnvironmentalData& data);

    void readSulfurDioxide(EnvironmentalData& data);

private:

    ADS1115 m_ads;

    bool m_connected;
};

#endif