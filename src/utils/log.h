#ifndef LOG_H
#define LOG_H

#include <Arduino.h>

class Log
{
public:
    static void begin();

    static void info(const String& module,
                     const String& message);

    static void warning(const String& module,
                        const String& message);

    static void error(const String& module,
                      const String& message);

    static void debug(const String& module,
                      const String& message);

    static void state(const String& from,
                      const String& to);

    static void separator();
};

#endif