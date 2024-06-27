
#ifndef _SAMPLE_SCENE_CPP
#define _SAMPLE_SCENE_CPP

#include <smash.h>
#include <Prefabs/FallingBlock.cpp>

class SampleScene : public smash::Scene {

    public:
        SampleScene() {
            instantiate(std::make_shared<FallingBlock>(5.0f, 0.0f));
        }
};

#endif