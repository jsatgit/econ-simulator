#ifndef RESOURCE_H
#define RESOURCE_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "textCreator.h"
#include "gameWindow.h"
#include "particle.h"

class Resource : public Particle
{
private:
public:
    Resource();
    void render() override;
    void onBeginCollisionWith(Particle& particle) override;
    void onEndCollisionWith(Particle& particle) override;
    bool collidesWith(const Particle& particle) override;
};

#endif /* RESOURCE_H */
