#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <unordered_set>

#include "textCreator.h"
#include "gameWindow.h"

class Particle
{
private:
public:
    Particle(float size, float value);
    virtual ~Particle();

    void setPosition(const sf::Vector2f& position);

    const sf::Vector2f& getPosition() const;
    int getSize() const;

    void addCollider(Particle& Particle);
    void removeCollider(Particle& Particle);
    virtual bool collidesWith(const Particle& particle) = 0;
    virtual void tick();
    virtual void render() = 0;
    virtual bool exists() const;
    virtual void move();
    virtual bool isResource() const;
protected:
    std::unordered_set<Particle*> m_colliders;
    sf::Vector2f m_position;
    float m_size;
    float m_original_size;
    float m_value;
    float m_original_value;

    virtual void onBeginCollisionWith(Particle& particle);
    virtual void onEndCollisionWith(Particle& particle);
};

#endif /* PARTICLE_H */
