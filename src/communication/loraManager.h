#ifndef LORA_MANAGER_H
#define LORA_MANAGER_H

#include <Arduino.h>
#include <RadioLib.h>

class LoRaManager
{
public:
    LoRaManager();
    bool begin();
    bool send(const String& packet);
    bool receive(String& packet);
    bool isConnected() const;
    float getRSSI() const;
    float getSNR() const;
private:
    Module m_module;
    SX1262 m_radio;
    bool m_connected;
    float m_lastRSSI;
    float m_lastSNR;
};

#endif