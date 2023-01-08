#include "Game.hpp"

Game::Game() : window() {
    this->window = new Window();
    this->window->Init(1024, 768, "Brave New World");
}

void Game::Update() {
    this->window->Update();
}
//
//void Game::LateUpdate() {}
//void Game::Draw() {}
//
bool Game::IsRunning() {
    return this->window->IsOpen();
}
