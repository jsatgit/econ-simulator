#include "game.h"
#include "gameWindow.h"
#include <iostream>

Game::Game()
{
}

void Game::configure(const Config& config)
{
    GameWindow& gameWindow = GameWindow::instance();
    gameWindow.setWidth(config.windowWidth);
    gameWindow.setHeight(config.windowHeight);
    gameWindow.setScale(config.windowScale);
    gameWindow.setFramerate(config.framerate);
    int numMonsters = 10;
    for (int i = 0; i < numMonsters; ++i) {
        Monster monster(1);
        monster.setSpeed(10);
        monster.setPosition(sf::Vector2f(100,100));
        m_monsters.push_back(monster);
    }
    int numHills = 1;
    for (int i = 0; i < numHills; ++i) {
        Hill hill(50, 10);
        hill.setPosition(sf::Vector2f(100,100));
        m_hills.push_back(hill);
    }
}

void Game::start()
{
    GameWindow::instance().open();
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
