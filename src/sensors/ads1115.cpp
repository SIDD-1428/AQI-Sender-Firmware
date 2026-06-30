#include "ads1115.h"

#include "../config/config.h"
#include "../utils/log.h"

ADS1115::ADS1115(){
    m_connected = false;
}

bool ADS1115::begin(){
    Log::info("ADS1115", "Initializing...");
    if (!m_ads.begin(Config::ADS1115_I2C_ADDRESS)){
        Log::error("ADS1115", "ADC not detected");
        m_connected = false;
        return false;
    }

    // Configure Gain
    m_ads.setGain(GAIN_ONE);
    m_connected = true;
    Log::info("ADS1115", "ADC detected");
    return true;
}

int16_t ADS1115::readRaw(uint8_t channel){
    if (!m_connected){
        Log::warning("ADS1115", "Read requested while disconnected");
        return 0;
    }

    if (channel > 3){
        Log::error("ADS1115", "Invalid channel");
        return 0;
    }
    return m_ads.readADC_SingleEnded(channel);
}

float ADS1115::readVoltage(uint8_t channel){
    int16_t raw = readRaw(channel);
    return raw * Config::ADS1115_LSB_SIZE / 1000.0f;
}

bool ADS1115::isConnected() const{
    return m_connected;
}