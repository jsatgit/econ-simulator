#include "game.h"
#include "gameWindow.h"

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
        Monster monster(2);
        monster.setSpeed(15);
        monster.setPosition(sf::Vector2f(i*5, i*5));
        m_monsters.push_back(monster);
    }
    Monster monster(2);
    monster.setSpeed(15);
    monster.setGold(2);
    monster.setPosition(sf::Vector2f(100,100));
    m_monsters.push_back(monster);
    int numHills = 1;
    for (int i = 0; i < numHills; ++i) {
        Hill hill(60, 60);
        hill.setPosition(sf::Vector2f(50, 50));
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
        monster.move(); 
    }
    for (int i = 0; i < m_monsters.size(); ++i) {
        for (int j = i+1; j < m_monsters.size(); ++j) {
            if (m_monsters[i].collidesWith(m_monsters[j])) {
                m_monsters[i].addCollider(m_monsters[j]);
                m_monsters[j].addCollider(m_monsters[i]);
            } else {
                m_monsters[i].removeCollider(m_monsters[j]);
                m_monsters[j].removeCollider(m_monsters[i]);
            }
        }
    }
}

void Game::render()
{
    for (auto& hill: m_hills) {
        hill.render(); 
    }
    for (auto& monster: m_monsters) {
        monster.render(); 
        monster.clear();
    }
}
