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
    Resource(float size);
    void render() override;
    void onBeginCollisionWith(Particle& particle) override;
    void onEndCollisionWith(Particle& particle) override;
    bool collidesWith(const Particle& particle) override;
    bool isResource() const override;
    bool exists() const override;
    void consume(int amount);
};

#endif /* RESOURCE_H */
