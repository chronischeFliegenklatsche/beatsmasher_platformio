#ifndef _GLITTER_CPP
#define _GLITTER_CPP

#include <smash.h>

class Glitter : public smash::FragmentShader
{
protected:
    void fragment(size_t x, size_t y, color &_color) const override
    {
        if (_color != color::black)
        {
            float time = smash::Time::getRunningTime();

            // Generate rainbow colors using sine and cosine functions
            float r = 0.5f + 0.5f * std::sin(time + (float)x * 0.1f);
            float g = 0.5f + 0.5f * std::sin(time + (float)y * 0.1f);
            float b = 0.5f + 0.5f * std::sin(time + (float)x * 0.1f + (float)y * 0.1f);

            // Convert float [0, 1] to uint8_t [0, 255]
            uint8_t r_uint8 = static_cast<uint8_t>(r * 255.0f);
            uint8_t g_uint8 = static_cast<uint8_t>(g * 255.0f);
            uint8_t b_uint8 = static_cast<uint8_t>(b * 255.0f);

            // Assuming Color takes RGBA values with uint8_t channels
            _color = color(r_uint8, g_uint8, b_uint8); // 255 for full opacity
        }

        
    }
};

#endif