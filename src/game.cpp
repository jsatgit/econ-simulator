#include "game.h"
#include "gameWindow.h"

#include <iostream>
#include <algorithm>

using namespace std;

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

    // create monsters
    int numMonsters = 10;
    for (int i = 0; i < numMonsters; ++i) {
        Monster* monster = new Monster(2);
        monster->setSpeed(15);
        monster->setPosition(sf::Vector2f(i*8, i*8));
        monster->setHealthRate(60);
        m_particles.push_back(monster);
    }

    // create resources
    Resource* resource = new Resource(7);
    resource->setPosition(sf::Vector2f(50, 50));
    m_particles.push_back(resource);

    // create hills
    int numHills = 5;
    for (int i = 0; i < numHills; ++i) {
        Hill hill(30, 30);
        hill.setPosition(sf::Vector2f(i*30, i*30));
        m_hills.push_back(hill);
    }
}

void Game::start()
{
    GameWindow::instance().open();
}

void Game::applyCollisionDetection()
{
    for (int i = 0; i < m_particles.size(); ++i) {
        for (int j = i+1; j < m_particles.size(); ++j) {
            if (m_particles[i]->collidesWith(*m_particles[j])) {
                m_particles[i]->addCollider(*m_particles[j]);
                m_particles[j]->addCollider(*m_particles[i]);
            } else {
                m_particles[i]->removeCollider(*m_particles[j]);
                m_particles[j]->removeCollider(*m_particles[i]);
            }
        }
    }
}

void Game::removeDeadParticles()
{
    auto removeBegin = remove_if(m_particles.begin(), m_particles.end(), [](Particle* particle) {
        return !particle->isAlive();
    });
    m_particles.erase(removeBegin, m_particles.end());
}

void Game::tick()
{
    for (Particle* particle: m_particles) {
        particle->move();
    }
    applyCollisionDetection();
    removeDeadParticles();
    for (Particle* particle: m_particles) {
        particle->tick();
    }
}

void Game::render()
{
    for (auto& hill: m_hills) {
        hill.render();
    }
    for (Particle* particle: m_particles) {
        particle->render();
    }
}
