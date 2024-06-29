
#include <GameRuntime.hpp>

#ifdef ESP32
#include <Arduino.h>

void setup() {
    _SMASH_GAME_LIFETIME();
}

void loop() {
    smash::Diagnostics::print("Smash game lifetime has been terminated.");
    smash::Diagnostics::print("Press reset button on you ESP32 to restart the game.");
    delay(3000);
}
#endif