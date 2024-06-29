#ifndef _FALL_CPP
#define _FALL_CPP

#include <smash.h>

class Fall : public smash::BehaviourScript
{
    float m_Speed;
public:
    Fall() : m_Speed(1.0f) {}
    Fall(float speed) : m_Speed(speed) {}

    void setSpeed(float speed) { m_Speed = speed; }
    float getSpeed() { return m_Speed; }

    void update() override
    {
        smash::Transform* transform = (smash::Transform*)getGameObject()->getComponent("Transform").get();
        if (transform)
        {
            transform->translate(smash::Vector2(m_Speed * smash::Time::getDeltaTime(), 0.0f));
        }
    }

    Component* clone() const override
    {
        return new Fall(*this);
    }

    std::string getTypeName() const override
    {
        return "Fall";
    }
};

#endif