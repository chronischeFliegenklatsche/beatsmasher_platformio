
#include <GameRuntime.hpp>

#ifdef ARDUINO
#include <Arduino.h>

void setup()
{
    // Your code
    GameRuntime gameRuntime;
    _SMASH_ENGINE_LOOP(gameRuntime);
}

void loop()
{
    exit(0);
}
#endif