#ifndef RESOURCE_H
#define RESOURCE_H 

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "textCreator.h"
#include "gameWindow.h"

class Resource
{
private:
    sf::Vector2f m_position;
    int m_value;
    int m_size;
public:
    Resource();
    void setPosition(const sf::Vector2f& position);
    void render();
};

#endif /* RESOURCE_H */
