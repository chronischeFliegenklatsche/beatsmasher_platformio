#ifndef _RYTHM_GENERATOR_CPP
#define _RYTHM_GENERATOR_CPP

#include <smash.h>

class RythmGenerator : public smash::BehaviourScript
{
    float m_AnchorTimeStamp;
    size_t m_MaximumBeats = 8;
public:
    RythmGenerator() : smash::BehaviourScript(), m_AnchorTimeStamp(smash::Time::getRunningTime()) {}
    float generateNextTimeStamp()
    {
        constexpr float BPM = 120;
        constexpr float eightDuration = BPM * 0.48f / 1000.0f;
        m_AnchorTimeStamp += eightDuration * smash::Random::randomInt(1, 8);
        return m_AnchorTimeStamp;
    }

    std::string getTypeName() const override
    {
        return "ObjectSpawner";
    }

    Component *clone() const override
    {
        return new RythmGenerator();
    }   

    void update()
    {
        
    }
};

#endif