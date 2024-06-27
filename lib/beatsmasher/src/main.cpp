
#include <GameRuntime.hpp>

#ifdef _WIN32
int main()
{
    GameRuntime gameRuntime;
    _SMASH_ENGINE_LOOP(gameRuntime);
}
#endif