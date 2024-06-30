#ifndef _OBJECT_SPAWNER_CPP
#define _OBJECT_SPAWNER_CPP

#include <smash.h>

class ObjectSpawner : public smash::BehaviourScript
{
    std::unique_ptr<smash::GameObject> m_OriginalObject;
public:
    ObjectSpawner() : BehaviourScript()
    {

    }

    void bindOriginalObject(std::unique_ptr<smash::GameObject> originalObject)
    {
        m_OriginalObject = std::move(originalObject);
    }

    void spawnObject(float x, float y)
    {
        spawnObject(vec2(x, y));
    }

    void spawnObject(vec2 position)
    {
        auto copiedObject = std::make_shared<smash::GameObject>(*m_OriginalObject);
        instantiate(copiedObject);
    }

    std::string getTypeName() const override
    {
        return "ObjectSpawner";
    }

    Component *clone() const override
    {
        return new ObjectSpawner();
    }   

    void update()
    {
        
    }


};

#endif