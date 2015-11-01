#ifndef MONSTER_H
#define MONSTER_H

#include <SFML/System/Vector2.hpp>

class Monster 
{
private:
    sf::Vector2f m_position;
    int m_size;

public:
    Monster(int size);
    void setPosition(const sf::Vector2f& position);
    void randomWalk();
    void render();
};

#endif /* MONSTER_H */
