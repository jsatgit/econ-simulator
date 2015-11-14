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
    bool m_hasCollision;
    bool checkTurn();
    sf::Vector2f m_goal;

public:
    Monster(int size);
    void setPosition(const sf::Vector2f& position);
    const sf::Vector2f& getPosition() const;
    int getSize() const;
    void setSpeed(int speed);
    void move();
    void render();
    void clear();
    bool collidesWith(const Monster& monster);
    void addCollider(const Monster& monster);
};

#endif /* MONSTER_H */
