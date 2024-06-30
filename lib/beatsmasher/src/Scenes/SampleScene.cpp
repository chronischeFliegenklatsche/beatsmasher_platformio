#ifndef _SAMPLE_SCENE_CPP
#define _SAMPLE_SCENE_CPP

#include <smash.h>
#include "../Prefabs/ToneBlock.cpp"

class SampleScene : public smash::Scene
{
public:
    SampleScene() : Scene()
    {
        instantiate(std::make_shared<ToneBlock>(0, 0, 24));
    }
};

#endif