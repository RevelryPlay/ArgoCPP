#pragma once

#include "Game.hpp"

namespace Argo {
    Game::Game() : window() {
        this->window = new Window(1024, 768, "Hello World");
    }

    void Game::Update() {
        this->window->Update();
//        this->window->GetFPS();
    }

    void Game::LateUpdate() {}
    void Game::Draw() {}

    bool Game::IsRunning() {
        return this->window->IsOpen();
    }

    void Game::Close() {
        this->window->Close();
    }
}
