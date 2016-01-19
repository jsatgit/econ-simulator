#include "particle.h"

#include <string>

using namespace sf;
using namespace std;

Particle::Particle(float size, float value) :
    m_size(size),
    m_original_size(size),
    m_value(value),
    m_original_value(value)
{
}

void Particle::setPosition(const Vector2f& position)
{
    m_position = position;
}

const sf::Vector2f& Particle::getPosition() const
{
    return m_position;
}

int Particle::getSize() const
{
    return m_size;
}

void Particle::addCollider(Particle* particle)
{
    auto res = m_colliders.insert(particle);
    if (res.second) {
        onBeginCollisionWith(particle);
    }
}

void Particle::removeCollider(Particle* particle)
{
    auto erased = m_colliders.erase(particle);
    if (erased) {
        onEndCollisionWith(particle);
    }
}

void Particle::onBeginCollisionWith(Particle* particle)
{
}

void Particle::onEndCollisionWith(Particle* particle)
{
}

bool Particle::exists() const
{
    return true;
}

void Particle::tick()
{
}

void Particle::move()
{
}

bool Particle::isResource() const
{
    return false;
}

Particle::~Particle()
{
    for (auto& particle : m_colliders) {
        particle->removeCollider(this);
    }
}
