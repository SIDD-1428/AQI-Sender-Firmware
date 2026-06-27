#include "utils/log.h"

#include "config/config.h"
#include "config/constants.h"
#include "config/build.h"

void Log::begin()
{
    Serial.begin(Constants::SERIAL_BAUD);

    while (!Serial)
    {
        delay(10);
    }

    Serial.println();

    Serial.println("==================================================");
    Serial.println(Config::FIRMWARE_NAME);

    Serial.print("Version : ");
    Serial.println(Config::FIRMWARE_VERSION);

    Serial.print("Node ID : ");
    Serial.println(Config::NODE_ID);

    Serial.print("Author  : ");
    Serial.println(Build::AUTHOR);

    Serial.print("Build   : ");
    Serial.print(Build::DATE);
    Serial.print(" ");
    Serial.println(Build::TIME);

    Serial.println("==================================================");
    Serial.println();

    info("System", "Logger Initialized");
}

void Log::info(const String& module,
               const String& message)
{
    Serial.print("[INFO][");
    Serial.print(module);
    Serial.print("] ");
    Serial.println(message);
}

void Log::warning(const String& module,
                  const String& message)
{
    Serial.print("[WARNING][");
    Serial.print(module);
    Serial.print("] ");
    Serial.println(message);
}

void Log::error(const String& module,
                const String& message)
{
    Serial.print("[ERROR][");
    Serial.print(module);
    Serial.print("] ");
    Serial.println(message);
}

void Log::debug(const String& module,
                const String& message)
{
    if (Config::DEBUG_MODE)
    {
        Serial.print("[DEBUG][");
        Serial.print(module);
        Serial.print("] ");
        Serial.println(message);
    }
}

void Log::state(const String& from,
                const String& to)
{
    Serial.print("[STATE] ");
    Serial.print(from);
    Serial.print(" -> ");
    Serial.println(to);
}

void Log::separator()
{
    Serial.println("--------------------------------------------------");
}