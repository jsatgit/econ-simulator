#include "positioner.h"

using namespace sf;

Positioner& Positioner::instance()
{
    static Positioner instance;
    return instance;
}

Vector2f Positioner::next(const Vector2f& current)
{
    int directionX = distribution(generator) - 1;
    int directionY = distribution(generator) - 1;
    return Vector2f(current.x + directionX, current.y + directionY);
}
