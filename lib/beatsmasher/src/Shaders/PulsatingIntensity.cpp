#ifndef _PULSATING_INTENSITY_CPP
#define _PULSATING_INTENSITY_CPP

#include <smash.h>
#include <smash/sh.hpp>

class PulsatingIntensity : public smash::FragmentShader
{
    void fragment(size_t x, size_t y, color& _color) const override
    {
        vec2 pos = *(vec2*)(gp("m_Position"));
        vec2 scal = *(vec2*)(gp("m_Scale"));
        
        if ((float)x >= pos.x && (float)x < pos.x + scal.x && (float)y >= pos.y && (float)y < pos.y + scal.y)
        {
            float time = smash::Time::getRunningTime();
            
            // Pulsfrequenz
            float frequency = 2.0f; // Ändern Sie diesen Wert, um die Pulsgeschwindigkeit anzupassen
            
            // Berechnen Sie den Pulswert zwischen 0.2 und 1 (um zu verhindern, dass es komplett dunkel wird)
            float pulse = 0.6f + 0.4f * std::sin(time * frequency);
            
            // Basisfarbe
            color baseColor = _color;  // Rot
            
            uint8_t r = static_cast<uint8_t>(baseColor.r * pulse);
            uint8_t g = static_cast<uint8_t>(baseColor.g * pulse);
            uint8_t b = static_cast<uint8_t>(baseColor.b * pulse);
            
            _color = color(r, g, b);
        }
    }
};

#endif