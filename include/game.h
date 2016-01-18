#ifndef GAME_H
#define GAME_H

#include <vector>

#include "config.h"
#include "monster.h"
#include "hill.h"
#include "resource.h"
#include "particle.h"

class Game
{
private:
    std::vector<Hill> m_hills;
    std::vector<std::unique_ptr<Particle>> m_particles;

    void applyCollisionDetection();
    void removeDeadParticles();

public:
    Game();
    void configure(const Config& config);
    void start();
    void tick();
    void render();
};

#endif /* GAME_H */
