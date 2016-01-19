#ifndef CONSUMER_H
#define CONSUMER_H

#include <SFML/System/Vector2.hpp>
#include "turnCounter.h"
#include "particle.h"
#include "item.h"

class Consumer : public Particle
{
private:
    TurnCounter m_moveCounter;
    TurnCounter m_healthCounter;
    int m_healthRate;
    int m_health;
    int m_original_health;
    int m_speed;
    int m_original_speed;
    int m_gold;
    int m_food;
    Consumer* m_previousTrader;

    bool m_hasCollision;
    sf::Vector2f m_goal;

    void onBeginCollisionWith(Particle& particle) override;
    void onEndCollisionWith(Particle& particle) override;

    void loseHealth();
    void eat(int amount);
    bool isHealthy();
    void tradeWith(Consumer& consumer);

public:
    Consumer(float size, int health, int speed);
    ~Consumer();

    int setSpeed(int speed);
    void setHealthRate(int rate);

    int askGold() const;
    bool exists() const override;

    void move() override;
    void render() override;
    bool collidesWith(const Particle& particle) override;
    void addCollider(Consumer& monster);
    void removeCollider(Consumer& monster);
    void tick() override;
    bool isWillingToSell(Item item, int quantity, int price);
    int withdraw(Item item, int quantity);
    int deposit(Item item, int quantity);
    void setGold(int quantity);
    void setPreviousTrader(Consumer* consumer);
};

#endif /* CONSUMER_H */
