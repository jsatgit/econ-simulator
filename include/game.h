#ifndef GAME_H
#define GAME_H

#include <vector>

#include "config.h"
#include "monster.h"

class Game
{
private:
    std::vector<Monster> m_monsters;

public:
    Game();
    void configure(const Config& config);
    void start();
    void tick();
    void render();
};

#endif /* GAME_H */
