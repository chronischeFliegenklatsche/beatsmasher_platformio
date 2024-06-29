#ifndef FALLING_BLOCK_CPP
#define FALLING_BLOCK_CPP

#include <smash.h>
#include "Scripts/Fall.cpp"

class FallingBlock : public smash::GameObject {

    public:
        FallingBlock(float x, float y) : GameObject() {
            addComponent(std::make_shared<smash::Transform>(smash::Vector2(0, 0)));
            addComponent(std::make_shared<smash::RectangleRenderer>(smash::Vector2(4), smash::Color(0, 0, 255, 255)));
            addComponent(std::make_shared<Fall>(1.0f));
        }
};

#endif