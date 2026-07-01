#include "sensorManager.h"
#include "../utils/log.h"
#include "../config/config.h"

SensorManager::SensorManager(){
    m_connected = false;
}

bool SensorManager::begin(){
    Log::info("SensorManager","Initializing...");

    bool bmeReady=m_bme280.begin();
    bool pmsReady=m_pms7003.begin();
    bool gasReady=m_gasManager.begin();

    m_connected=bmeReady||pmsReady||gasReady;

    if(m_connected){
        Log::info("SensorManager","Initialization Complete");
    }else{
        Log::error("SensorManager","No sensors available");
    }

    return m_connected;
}

bool SensorManager::read(EnvironmentalData& data){
    if(!m_connected){
        Log::warning("SensorManager","Read requested while disconnected");
        return false;
    }

    //metadata
    data.clear();
    data.nodeID=Config::NODE_ID;
    data.uptime=millis();

    //read sensors
    bool climateOK = m_bme280.read(data);
    if(!climateOK){
        Log::warning("SensorManager","Climate sensor unavailable");
    }
    bool particulateOK=m_pms7003.read(data);
    if(!particulateOK){
        Log::warning("SensorManager","Particulate sensor unavailable");
    }
    bool gasOK=m_gasManager.read(data);
    if(!gasOK){
        Log::warning("SensorManager","Gas sensors unavailable");
    }

    
    //update timestamp
    data.lastUpdated=millis();
    Log::debug("SensorManager","Sensor acquisition complete");
    return true;
}

bool SensorManager::isConnected()const{
    return m_bme280.isConnected();
    return m_pms7003.isConnected();
    return m_gasManager.isConnected();
}