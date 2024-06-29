#ifndef _PULSE_CPP
#define _PULSE_CPP

#include <smash.h>

class Pulse : public smash::BehaviourScript
{
    float m_Speed;
    int m_Factor = 255.0f;
public:
    Pulse() : m_Speed(50.0f) {}
    Pulse(float speed) : m_Speed(speed) {}

    void setSpeed(float speed) { m_Speed = speed; }
    float getSpeed() { return m_Speed; }

    void update() override
    {
         // 19
         // Zeilen
         // werden
         // jetzt
         // gerade
         // geschrieben
         // für
         // knobi lochi :3
         // ich kann nicht
         // zählen
        smash::RectangleRenderer* renderer = (smash::RectangleRenderer*)getGameObject()->getComponent("RectangleRenderer").get();
        if (renderer)
        {
            if (m_Factor >= 255.0f)
            {
                m_Factor -= std::max<int>(smash::Time::getDeltaTime() * m_Speed, 255.0f);
            }
                
            else if (m_Factor < 255.0f)
            {
                m_Factor -= std::max<int>(smash::Time::getDeltaTime() * m_Speed, 0.0f);
            }
            renderer->setColor(smash::Color(m_Factor, 0, 0, 255));
            
        }
    }

    Component* clone() const override
    {
        return new Pulse(*this);
    }

    std::string getTypeName() const override
    {
        return "Pulse";
    }
};

#endif