#include "packetBuilder.h"
#include  "../config/config.h"

PacketBuilder::PacketBuilder() : m_packet("") {
    clear();
}

String PacketBuilder::build(const EnvironmentalData& data){
    clear();

    //build packet
    appendMetadata(data);
    appendClimate(data);
    appendParticulates(data);
    appendGases(data);

    //checksum
    uint16_t crc=calculateChecksum(m_packet);

    m_packet += "CRC= ";
    m_packet+=String(crc);
    m_packet += ";";

    return m_packet;
}

void PacketBuilder::clear(){
    m_packet ="";
}
void PacketBuilder::appendMetadata(const EnvironmentalData& data){

    m_packet += "VERSION = ";
    m_packet += String(Config::PROTOCOL_VERSION);
    m_packet += ";";

    m_packet += "Node_ID = ";
    m_packet += data.nodeID;
    m_packet += ";";

    m_packet += "Sequence_Number = ";
    m_packet += String(data.sequenceNumber);
    m_packet += ";";
}

void PacketBuilder::appendClimate(const EnvironmentalData& data){
    m_packet += "Temperature = ";
    m_packet += String(data.temperature, 2);
    m_packet += ";";

    m_packet += "Humidity = ";
    m_packet += String(data.humidity, 2);
    m_packet += ";";

    m_packet += "Pressure = ";
    m_packet += String(data.pressure, 2);
    m_packet += ";";
}

void PacketBuilder::appendParticulates(const EnvironmentalData& data){
    m_packet += "PM_1_0 = ";
    m_packet += String(data.pm1_0,2);
    m_packet += ";";

    m_packet += "PM2_5 = ";
    m_packet += String(data.pm2_5, 2);
    m_packet += ";";

    m_packet += "PM_10 = ";
    m_packet += String(data.pm10, 2);
    m_packet += ";";
}


void PacketBuilder :: appendGases(const EnvironmentalData& data){
    m_packet += "O3 =";
    m_packet += String(data.ozone, 2);
    m_packet+= ";";

    m_packet += "NO2 =";
    m_packet += String(data.nitrogenDioxide, 2);
    m_packet += ";";
    
    m_packet+= "CO =";
    m_packet += String(data.carbonMonoxide, 2);
    m_packet += ";";

    m_packet += "NH3 =";
    m_packet += String(data.ammonia, 2);
    m_packet+= ";";

    m_packet += "SO2 = ";
    m_packet += String(data.sulfurDioxide, 2);
    m_packet += ";";
}



uint16_t PacketBuilder :: calculateChecksum (const String& packet) const{
    uint16_t checksum =0;
    for(size_t i = 0; i<packet.length(); i++){
        checksum += static_cast<uint8_t>(packet[i]);
    }
    return checksum;
}