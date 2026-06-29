#include "environmentalData.h"
#include "../utils/log.h"

EnvironmentalData::EnvironmentalData(){
    clear();
}

void EnvironmentalData::clear(){
    //metadta
    sequenceNumber=0;
    uptime=0;

    //climate
    temperature=0.0f;
    humidity=0.0f;
    pressure=0.0f;

    //particles
    pm1_0=0.0f;
    pm2_5=0.0f;
    pm10=0.0f;

    //gases
    ozone=0.0f;
    nitrogenDioxide=0.0f;
    carbonMonoxide=0.0f;
    ammonia=0.0f;
    sulfurDioxide=0.0f;

    //status
    hasClimateData=false;
    hasParticulateData=false;
    hasGasData=false;

    validated=false;

    //diagnostics
    lastUpdated=0;
}


bool EnvironmentalData::isComplete() const{
    return hasClimateData && hasParticulateData && hasGasData;
}

bool EnvironmentalData::isValid() const{
    return validated;
}

void EnvironmentalData::print() const{
    Log::separator();
    Log::info("Environment","Environmental Snapshot");
    Log::separator();
    Log::info("NodeID", nodeID);
    Log::info("Sequence", String(sequenceNumber));
    Log::info("Uptime",String(uptime)+" ms");
    Log::separator();
    Log::info("Temperature", String(temperature) + " °C");
    Log::info("Humidity", String(humidity)+" %");
    Log::info("Pressure", String(pressure)+ " hpa");
    Log::separator();
    Log::info("PM1.0", String(pm1_0));
    Log::info("PM2.5", String(pm2_5));
    Log::info("PM10", String(pm10));
    Log::separator();
    Log::info("Ozone", String(ozone));
    Log::info("NO2", String(nitrogenDioxide));
    Log::info("CO", String(carbonMonoxide));
    Log::info("NH3", String(ammonia));
    Log::info("SO2", String(sulfurDioxide));
    Log::separator();
    Log::info("Climate", hasClimateData? "Yes": "No");
    Log::info("Particulates", hasParticulateData? "Yes":"No");
    Log::info("Gas", hasGasData? "Yes":"No");
    Log::info("Complete", isComplete()? "Yes":"No");
    Log::info("Validated", isValid()? "Yes":"No");
    Log::separator();
}