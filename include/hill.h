#ifndef HILL_H
#define HILL_H

#include <SFML/System/Vector2.hpp>

class Hill 
{
private:
    int m_radius;
    int m_height;
    sf::Vector2f m_position;

public:
    Hill(int radius, int height);
    void setPosition(const sf::Vector2f& position);
    void move();
    void render();
};

#endif /* HILL_H */
