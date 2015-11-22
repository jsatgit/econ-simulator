#ifndef MONSTER_H
#define MONSTER_H

#include <SFML/System/Vector2.hpp>
#include <unordered_set>
#include "turnCounter.h"

class Monster
{
private:
    TurnCounter m_moveCounter;
    TurnCounter m_healthCounter;
    sf::Vector2f m_position;
    int m_healthRate;
    int m_health;
    int m_size;
    int m_speed;
    int m_gold;

    bool m_hasCollision;
    sf::Vector2f m_goal;
    std::unordered_set<Monster*> m_colliders;

    void onBeginCollisionWith(Monster& monster);
    void onEndCollisionWith(Monster& monster);

    void loseHealth();

public:
    Monster(int size);

    void setPosition(const sf::Vector2f& position);
    void setSpeed(int speed);
    void setGold(int gold);
    void giveGold(int gold);
    void setHealthRate(int rate);

    const sf::Vector2f& getPosition() const;
    int getSize() const;
    int askGold() const;
    bool isAlive();

    void move();
    void render();
    bool collidesWith(const Monster& monster);
    void addCollider(Monster& monster);
    void removeCollider(Monster& monster);
    void tick();
};

#endif /* MONSTER_H */
