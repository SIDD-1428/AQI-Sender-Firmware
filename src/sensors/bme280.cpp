#include "bme280.h"

#include "../config/config.h"
#include "../utils/log.h"

BME280::BME280(){
    m_connected=false;  
}

bool BME280::begin(){
    Log::info("BME280","Initializing...");
    if(!m_sensor.begin(Config::BME280_I2C_ADDRESS)){
        Log::error("BME280","Sensor not detected");
        m_connected=false;
        return false;
    }

    m_connected=true;
    Log::info("BME280","Sensor detected");
    return true;
}

bool BME280::read(EnvironmentalData& data){
    if(!m_connected){
        Log::warning("BME280","Read requested while disconnected");
        data.hasClimateData=false;
        return false;
    }

    //reading sensor
    float temperature = m_sensor.readTemperature();
    if(isnan(temperature)){
        Log::error("BME280","Temperature read failed");
        data.hasClimateData=false;
        return false;
    }
    
    float humidity= m_sensor.readHumidity();
    if(isnan(humidity)){
        Log::error("BME280","Humidity read failed");
        data.hasClimateData=false;
        return false;
    }

    float pressure= m_sensor.readPressure();
    if(isnan(pressure)){
        Log::error("BME280","Pressure read failed");
        data.hasClimateData=false;
        return false;
    }

    data.temperature= temperature;
    data.humidity=humidity;
    data.pressure=pressure/100.0f;

    //status update
    data.hasClimateData=true;
    data.lastUpdated=millis();

    Log::debug("BME280","Climate data updated");
    return true;
}

bool BME280::isConnected() const{
    return m_connected;
}


