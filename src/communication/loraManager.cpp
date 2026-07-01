#include "loraManager.h"
#include <SPI.h>

#include "../config/config.h"
#include "../utils/log.h"

LoRaManager::LoRaManager()
    : m_module(
          Config::LORA_NSS_PIN,
          Config::LORA_DIO1_PIN,
          Config::LORA_RST_PIN,
          Config::LORA_BUSY_PIN),
      m_radio(&m_module)
{
    m_connected = false;
    m_lastRSSI = 0.0f;
    m_lastSNR = 0.0f;
}

bool LoRaManager::begin()
{
    Log::info("LoRa", "Initializing...");
    SPI.begin();    
    Log::info("LoRa", "SPI initialized");
    
    int state = m_radio.begin(
        Config::LORA_FREQUENCY,
        Config::LORA_BANDWIDTH,
        Config::LORA_SPREADING_FACTOR,
        Config::LORA_CODING_RATE,
        Config::LORA_SYNC_WORD,
        Config::LORA_TX_POWER,
        Config::LORA_PREAMBLE_LENGTH
    );

    if (state != RADIOLIB_ERR_NONE)
    {
        Log::error("LoRa", "Initialization failed");
        Log::error("LoRa", String(state));

        m_connected = false;
        return false;
    }

    if (Config::LORA_ENABLE_CRC)
    {
        m_radio.setCRC(true);
    }

    m_connected = true;

    Log::info("LoRa", "Ready");

    return true;
}

bool LoRaManager::send(const String& packet)
{
    if (!m_connected)
    {
        Log::warning("LoRa", "Send requested while disconnected");
        return false;
    }

    int state = m_radio.transmit(packet.c_str());

    if (state != RADIOLIB_ERR_NONE)
    {
        Log::error("LoRa", "Transmission failed");
        Log::error("LoRa", String(state));

        return false;
    }

    m_lastRSSI = m_radio.getRSSI();
    m_lastSNR = m_radio.getSNR();

    Log::debug("LoRa", "Packet transmitted");

    return true;
}

bool LoRaManager::receive(String& packet)
{
    if (!m_connected)
    {
        return false;
    }

    int state = m_radio.receive(packet);

    if (state != RADIOLIB_ERR_NONE)
    {
        return false;
    }

    m_lastRSSI = m_radio.getRSSI();
    m_lastSNR = m_radio.getSNR();

    Log::debug("LoRa", "Packet received");

    return true;
}

bool LoRaManager::isConnected() const
{
    return m_connected;
}

float LoRaManager::getRSSI() const
{
    return m_lastRSSI;
}

float LoRaManager::getSNR() const
{
    return m_lastSNR;
}