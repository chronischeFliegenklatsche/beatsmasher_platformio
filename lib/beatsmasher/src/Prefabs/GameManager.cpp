#ifndef _GAME_MANAGER_CPP
#define _GAME_MANAGER_CPP

#include <smash.h>
#include "../Prefabs/ToneBlock.cpp"
#include "../Scripts/ObjectSpawner.cpp"
#include "../Scripts/RythmGenerator.cpp"

class GameManager : public smash::GameObject
{

public:
    GameManager() : smash::GameObject()
    {

        // Initialize object spawner
        auto toneBlockSpawner = std::make_shared<ObjectSpawner>();
        toneBlockSpawner->bindOriginalObject(std::move(std::unique_ptr<ToneBlock>(new ToneBlock(0, 0, 4))));

        // Initialize rythm generator
        auto rythmGenerator = std::make_shared<RythmGenerator>();
        rythmGenerator->generateNextTimeStamp();

        // Add components
        addComponent(toneBlockSpawner);
        addComponent(rythmGenerator);
    }

    

};

#endif