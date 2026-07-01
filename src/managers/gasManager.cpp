#include "gasManager.h"
#include "../utils/log.h"

GasManager::GasManager(){
    m_connected=false;
}

bool GasManager::begin(){
    Log::info("GasManager","Initializing...");
    m_connected=m_ads.begin();

    if(m_connected){
        Log::info("GasManager","Ready");
    }else{
        Log::error("GasManager","Initialization failed");
    }
    return m_connected;
}
                                                                                                                                                                              
bool GasManager::read(EnvironmentalData& data){
    if(!m_connected){
        Log::warning("GasManager","Read requested while disconnected");
        data.hasGasData=false;
        return false;
    }

    readOzone(data);
    readNitrogenDioxide(data);
    readCarbonMonoxide(data);
    readAmmonia(data);
    readSulfurDioxide(data);

    data.hasGasData=true;
    data.lastUpdated=millis();
    Log::debug("GasManager","Gas data updated");
    return true;
}

void GasManager::readOzone(EnvironmentalData& data){
    data.ozone=m_ads.readVoltage(0);
}

void GasManager::readNitrogenDioxide(EnvironmentalData& data){
    data.nitrogenDioxide=m_ads.readVoltage(3);
}

void GasManager::readCarbonMonoxide(EnvironmentalData& data){
    data.carbonMonoxide=m_ads.readVoltage(2);
}

void GasManager::readAmmonia(EnvironmentalData& data){
    data.ammonia=m_ads.readVoltage(1);
}

void GasManager::readSulfurDioxide(EnvironmentalData& data){
    data.sulfurDioxide=0.0f;
}

bool GasManager::isConnected() const{
    return m_connected;
}