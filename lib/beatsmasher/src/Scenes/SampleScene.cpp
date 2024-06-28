
#ifndef _SAMPLE_SCENE_CPP
#define _SAMPLE_SCENE_CPP

#include <smash.h>
#include <Prefabs/FallingBlock.cpp>

class SampleScene : public smash::Scene {

    public:
        SampleScene() : Scene() {
            instantiate(std::make_shared<FallingBlock>(5.0f, 5.0f));
        }
};

#endif