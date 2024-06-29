#ifndef _TONE_BLOCK_CPP
#define _TONE_BLOCK_CPP

#include <smash.h>

class ToneBlock : public smash::GameObject
{   
    color *m_Color;
public:
    ToneBlock(float xPosition, float yPosition, size_t height) : GameObject(), m_Color(new color(255, 0, 0))
    {
        
        // Constant width
        constexpr size_t width = 4;
        
        // Initialize transform
        auto _transform = std::make_shared<smash::Transform>(vec2(xPosition, yPosition), vec2(width, height));

        // Initialize shader stack
        auto _shaderStack= std::make_shared<smash::FragmentShaderPass>();

        // Retrieving vertex pointers
        auto& _posRef = _transform->getPositionRef();
        auto& _scaleRef = _transform->getScaleRef();
        
        // Initialize rect shader
        auto _rectShader = std::unique_ptr<const smash::FragmentShader>(new smash::RectShader(&_posRef.x, &_posRef.y, &_scaleRef.x, &_scaleRef.y, m_Color));

        // Add rect shader to stack
        _shaderStack->bind(std::move(_rectShader));

        // Add components
        addComponent(_transform);
        addComponent(_shaderStack);
    }

    ~ToneBlock() override
    {
        delete m_Color;
    }


};

#endif