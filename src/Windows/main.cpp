#include "ArgoConfig.h"

// Windows Specific Code
#ifdef _WIN32
#include "System/Game.hpp"

int main(int, char **) {
    if (!Argo::Game::init())
    {
        fprintf(stderr, "Failed to initialize the game. See the logs above for more details.");
        return -1;
    }

    Argo::Game::run();
    Argo::Game::free();

    return 0;
}
#endif
