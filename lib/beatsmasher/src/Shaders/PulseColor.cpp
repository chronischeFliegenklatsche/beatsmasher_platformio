#ifndef _PULSE_COLOR_HPP
#define _PULSE_COLOR_HPP

#include <smash.h>
#include <smash/sh.hpp>

class PulseColor : public smash::FragmentShader
{
protected:
    void fragment(size_t x, size_t y, color& _color) const override
    {
        vec2 pos = *(vec2*)(gp("m_Position"));
        vec2 scal = *(vec2*)(gp("m_Scale"));
        
        if ((float)x >= pos.x && (float)x < pos.x + scal.x && (float)y >= pos.y && (float)y < pos.y + scal.y)
        {
            float time = smash::Time::getRunningTime();
            
            // Pulsfrequenz
            float frequency = 2.0f; // Ändern Sie diesen Wert, um die Pulsgeschwindigkeit anzupassen
            
            // Berechnen Sie den Pulswert zwischen 0 und 1
            float pulse = 0.5f + 0.5f * std::sin(time * frequency);
            
            // Interpolieren Sie zwischen zwei Farben
            color color1(255, 0, 0);   // Rot
            color color2(0, 0, 255);   // Blau
            
            uint8_t r = static_cast<uint8_t>(color1.r * pulse + color2.r * (1.0f - pulse));
            uint8_t g = static_cast<uint8_t>(color1.g * pulse + color2.g * (1.0f - pulse));
            uint8_t b = static_cast<uint8_t>(color1.b * pulse + color2.b * (1.0f - pulse));
            
            _color = color(r, g, b);
        }
    }
};

#endif