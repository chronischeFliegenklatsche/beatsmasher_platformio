#ifndef FALLING_BLOCK_CPP
#define FALLING_BLOCK_CPP

#include <smash.h>

class FallingBlock : public smash::GameObject {

    public:
        FallingBlock(float x, float y) : GameObject() {
            addComponent(std::make_shared<smash::Transform>(smash::Vector2(x, y)));
            addComponent(std::make_shared<smash::RectangleRenderer>(smash::Vector2(100.0f), smash::Color(255, 0, 0, 255)));
        }
};

#endif