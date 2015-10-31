#include "game.h"

Game::Game()
{
}

void Game::configure(const Config& config)
{
    int numMonsters = 10;
    for (int i = 0; i < numMonsters; ++i) {
        m_monsters.push_back(Monster());
    }
}

void Game::start()
{
    for (auto& monster: m_monsters) {
        monster.setPosition(sf::Vector2f(400,300));
    }
}

void Game::tick()
{
    for (auto& monster: m_monsters) {
        monster.move(); 
    }
}

void Game::render()
{
    for (auto& monster: m_monsters) {
        monster.render(); 
    }
}
