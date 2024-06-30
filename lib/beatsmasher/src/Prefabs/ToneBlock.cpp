#ifndef _TONE_BLOCK_CPP
#define _TONE_BLOCK_CPP

#include <smash.h>
#include "../Scripts/Move.cpp"
#include "../Shaders/Glitter.cpp"
#include "../Shaders/RainbowMadness.cpp"
#include "../Shaders/PulseColor.cpp"
#include "../Shaders/PulsatingIntensity.cpp"
#include "../Scripts/Move.cpp"

class ToneBlock : public smash::GameObject
{   
    color *m_Color;
public:
    ToneBlock(float xPosition, float yPosition, size_t height) : GameObject(), m_Color(new color(255, 0, 0))
    {
        
        // Constant width
        constexpr size_t width = 4;
        
        // Initialize transform
        auto transform = std::make_shared<smash::Transform>(vec2(xPosition, yPosition), vec2(height, width));

        // Initialize move script
        auto move = std::make_shared<Move>(1);

        // Initialize shader renderer
        auto shadRenderer = std::make_shared<smash::ShaderRenderer>();

        // Initialize shader attributes
        auto shattr = std::unique_ptr<smash::ShaderAttributes>(new smash::ShaderAttributes());
        shattr->setPointer("m_Position", &(transform->getPositionRef()));
        shattr->setPointer("m_Scale", &(transform->getScaleRef()));
        shattr->setPointer("m_Color", (void*)m_Color);
        shadRenderer->bindStartFrameShaderAttributes(std::move(shattr));

        // Initialize rect shader
        auto _rectShader = std::unique_ptr<smash::Shader>(new RainbowMadness());
        shadRenderer->bind(std::move(_rectShader));

        // Initialize glitter shader
        auto _glitter = std::unique_ptr<smash::Shader>(new PulsatingIntensity());
        shadRenderer->bind(std::move(_glitter));

        // Add components
        addComponent(transform);
        addComponent(shadRenderer);
        addComponent(move); 
    }

    ~ToneBlock() override
    {
        delete m_Color;
    }


};

#endif