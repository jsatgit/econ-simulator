#ifndef MONSTER_H
#define MONSTER_H

#include <SFML/System/Vector2.hpp>
#include <unordered_set>

class Monster
{
private:
    sf::Vector2f m_position;
    int m_size;
    int m_speed;
    int m_turnMax;
    int m_turnCount;
    int m_gold;
    bool m_hasCollision;
    bool checkTurn();
    sf::Vector2f m_goal;
    std::unordered_set<Monster*> m_colliders;
    void onBeginCollisionWith(Monster& monster);
    void onEndCollisionWith(Monster& monster);

public:
    Monster(int size);
    void setPosition(const sf::Vector2f& position);
    const sf::Vector2f& getPosition() const;
    int getSize() const;
    void setSpeed(int speed);
    void setGold(int gold);
    void move();
    void render();
    void clear();
    int askGold() const;
    bool collidesWith(const Monster& monster);
    void addCollider(Monster& monster);
    void removeCollider(Monster& monster);
    void giveGold(int gold);
};

#endif /* MONSTER_H */
