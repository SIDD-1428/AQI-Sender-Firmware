#ifndef PMS7003_H
#define PMS7003_H

#include <Arduino.h>

#include "../models/environmentalData.h"

class PMS7003{
    public:
        PMS7003(HardwareSerial& serial=Serial1);
        bool begin();
        bool read(EnvironmentalData& data);
        bool isConnected() const;
    private:
        bool readFrame();
        bool validateFrame() const;
        bool parseFrame(EnvironmentalData& data);
    
    private:
        HardwareSerial& m_serial;
        bool m_connected;
        static constexpr uint8_t FRAME_LENGTH=32;
        uint8_t m_buffer[FRAME_LENGTH];
};

#endif