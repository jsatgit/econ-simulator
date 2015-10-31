#ifndef MONSTER_H
#define MONSTER_H

#include <SFML/System/Vector2.hpp>

class Monster 
{
private:
    sf::Vector2f m_position;

public:
    void setPosition(sf::Vector2f position);
    void move();
    void render();
};

#endif /* MONSTER_H */
