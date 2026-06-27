#include <Arduino.h>

#include "config/config.h"
#include "config/constants.h"
#include "config/build.h"

#include "utils/log.h"

void setup()
{
    Log::begin();

    Log::info("System", "Boot Complete");
}

void loop()
{
}