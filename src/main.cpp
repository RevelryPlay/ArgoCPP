#include "ArgoConfig.h"
#include "System/Game.hpp"

int main(int, char **) {
    Argo::Game game = Argo::Game();

    // Get System Modules
    // Base Error Handlers
    // OS Specific Modules
    // File System Utilities
    // Loggers
    // Serializers
    // Asset Loaders
    // Save / Load
    // Settings Handler

    // Graphic Utilities
    // Audio Utilities
    // Input Utilities
    // Networking Utilities

    // Get Registered Extensions
    // Handle Preloads
    // Core Event Loop
    while (game.IsRunning()) {
        game.Update();
        game.LateUpdate();
        game.Draw();
    }

    game.Close();
}
