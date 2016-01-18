#ifndef GAME_H
#define GAME_H

#include <vector>

#include "config.h"
#include "monster.h"
#include "hill.h"
#include "resource.h"

class Game
{
private:
    std::vector<Monster> m_monsters;
    std::vector<Hill> m_hills;
    std::vector<Resource> m_resources;

    void applyCollisionDetection();
    void removeDeadMonsters();

public:
    Game();
    void configure(const Config& config);
    void start();
    void tick();
    void render();
};

#endif /* GAME_H */
