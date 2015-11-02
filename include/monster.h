#ifndef MONSTER_H
#define MONSTER_H

#include <SFML/System/Vector2.hpp>

class Monster 
{
private:
    sf::Vector2f m_position;
    int m_size;
    int m_speed;
    int m_turnMax;
    int m_turnCount;
    bool checkTurn();
    sf::Vector2f m_goal;

public:
    Monster(int size);
    void setPosition(const sf::Vector2f& position);
    void setSpeed(int speed);
    void move();
    void render();
};

#endif /* MONSTER_H */
