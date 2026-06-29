#include "pms7003.h"

#include "../config/config.h"
#include "../utils/log.h"

PMS7003::PMS7003(HardwareSerial& serial)
    : m_serial(serial)
{
    m_connected = false;
}

bool PMS7003::begin()
{
    Log::info("PMS7003", "Initializing...");

    m_serial.begin(
        Config::PMS7003_BAUD_RATE,
        SERIAL_8N1,
        Config::PMS7003_RX_PIN,
        Config::PMS7003_TX_PIN
    );

    m_connected = false;

    Log::info("PMS7003", "UART Initialized");

    return true;
}

bool PMS7003::read(EnvironmentalData& data)
{
    if (!readFrame())
    {
        m_connected = false;
        data.hasParticulateData = false;

        return false;
    }

    if (!validateFrame())
    {
        Log::warning("PMS7003", "Checksum validation failed");

        m_connected = false;
        data.hasParticulateData = false;

        return false;
    }

    m_connected = true;

    return parseFrame(data);
}

bool PMS7003::readFrame()
{
    while (m_serial.available())
    {
        if (m_serial.read() == 0x42)
        {
            if (!m_serial.available())
            {
                return false;
            }

            if (m_serial.peek() == 0x4D)
            {
                m_buffer[0] = 0x42;
                m_buffer[1] = m_serial.read();

                size_t bytesRead =
                    m_serial.readBytes(&m_buffer[2], FRAME_LENGTH - 2);

                return (bytesRead == FRAME_LENGTH - 2);
            }
        }
    }

    return false;
}

bool PMS7003::validateFrame() const
{
    // Header Check
    
    if (m_buffer[0] != 0x42)
        return false;

    if (m_buffer[1] != 0x4D)
        return false;

    // Checksum

    uint16_t checksum = 0;

    for (int i = 0; i < 30; i++)
    {
        checksum += m_buffer[i];
    }

    uint16_t receivedChecksum =
        (m_buffer[30] << 8) | m_buffer[31];

    return checksum == receivedChecksum;
}

bool PMS7003::parseFrame(EnvironmentalData& data)
{
    // Atmospheric PM Values
   

    data.pm1_0 =
        (m_buffer[10] << 8) | m_buffer[11];

    data.pm2_5 =
        (m_buffer[12] << 8) | m_buffer[13];

    data.pm10 =
        (m_buffer[14] << 8) | m_buffer[15];

    data.hasParticulateData = true;

    data.lastUpdated = millis();

    Log::debug(
        "PMS7003",
        "PM1.0=" + String(data.pm1_0) +
        " PM2.5=" + String(data.pm2_5) +
        " PM10=" + String(data.pm10)
    );

    return true;
}

bool PMS7003::isConnected() const
{
    return m_connected;
}