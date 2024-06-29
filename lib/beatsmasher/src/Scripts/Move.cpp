#ifndef _MOVE_CPP
#define _MOVE_CPP

#include <smash.h>

class Move : public smash::BehaviourScript
{
    float m_Speed;
public:
    Move(float speed) : BehaviourScript(), m_Speed(speed)
    {
        // Do nothing
    }

    void update() override
    {
        auto transform = (smash::Transform*)getGameObject()->getComponent("Transform").get();
        transform->translate(vec2(m_Speed * smash::Time::getDeltaTime(), 0));
    }

    std::string getTypeName() const override
    {
        return "Move";
    }

    Component* clone() const override
    {
        return new Move(m_Speed);
    }
};

#endif