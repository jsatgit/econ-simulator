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
    int numHills = 1;
    for (int i = 0; i < numHills; ++i) {
        m_hills.push_back(Hill(200, 10));
    }
}

void Game::start()
{
    for (auto& monster: m_monsters) {
        monster.setPosition(sf::Vector2f(400,300));
    }
    for (auto& hill: m_hills) {
        hill.setPosition(sf::Vector2f(100,100));
    }
}

void Game::tick()
{
    for (auto& monster: m_monsters) {
        monster.randomWalk(); 
    }
}

void Game::render()
{
    for (auto& hill: m_hills) {
        hill.render(); 
    }
    for (auto& monster: m_monsters) {
        monster.render(); 
    }
}
