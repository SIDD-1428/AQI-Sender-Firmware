#ifndef PACKET_BUILDER_H
#define PACKET_BUILDER_H

#include <Arduino.h>

#include "../models/environmentalData.h"

class PacketBuilder{
    public:
        PacketBuilder();
        String build(const EnvironmentalData& data);
        void clear();
        
    private:
        void appendMetadata(const EnvironmentalData& data);
        void appendClimate(const EnvironmentalData& data);
        void appendParticulates(const EnvironmentalData& data);
        void appendGases(const EnvironmentalData& data);
        uint16_t calculateChecksum(const String& packet) const;

    private:
        String m_packet;

};

#endif