#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "consumer.h"
#include "gameWindow.h"
#include "positioner.h"
#include "textCreator.h"
#include "resource.h"
#include <cmath>

#include <iostream>
#include <string>

using namespace sf;
using namespace std;

Consumer::Consumer(float size, int health, int speed) :
    Particle(size, 0),
    m_health(health),
    m_original_health(health),
    m_gold(100),
    m_food(10),
    m_previousTrader(nullptr),
    m_hasCollision(false),
    m_goal(Positioner::instance().generateGoal())
{
    m_original_speed = setSpeed(speed);
}

Consumer::~Consumer()
{
}

void Consumer::onBeginCollisionWith(Particle& particle)
{
    if (particle.isResource()) {
        Resource& resource = dynamic_cast<Resource&>(particle);
        resource.consume(1);
        m_food += 1;
    } else {
        Consumer& consumer = dynamic_cast<Consumer&>(particle);
        tradeWith(consumer);
    }
}

void Consumer::tradeWith(Consumer& consumer)
{
    if (&consumer != m_previousTrader && m_gold > 0 && m_health > 10) {
        int price = 1;
        int quantity = 1;
        if (consumer.isWillingToSell(FOOD, quantity, price)) {
            int actual = consumer.withdraw(FOOD, quantity);
            if (actual == quantity) {
                m_food += actual;
                consumer.deposit(GOLD, price);
                m_gold -= price;
            }
            consumer.setPreviousTrader(this);
        }
    }
}

void Consumer::setPreviousTrader(Consumer* consumer)
{
    m_previousTrader = consumer;
}

int Consumer::withdraw(Item item, int quantity)
{
    int actualWithdrawal = 0;
    int* itemToWithdraw = nullptr;
    switch(item) {
        case FOOD:
            itemToWithdraw = &m_food;
            break;
        case GOLD:
            itemToWithdraw = &m_gold;
            break;
    }
    int finalQuantity = *itemToWithdraw - quantity;
    if (finalQuantity >=0) {
        *itemToWithdraw -= quantity;
        actualWithdrawal = quantity;
    }
    return actualWithdrawal;
}

int Consumer::deposit(Item item, int quantity)
{
    int* itemToDeposit = nullptr;
    switch(item) {
        case FOOD:
            itemToDeposit = &m_food;
            break;
        case GOLD:
            itemToDeposit = &m_gold;
            break;
    }
    *itemToDeposit += quantity;
    return quantity;
}

bool Consumer::isWillingToSell(Item item, int quantity, int price)
{
    if (item == FOOD && m_food > 0) {
        return true;
    }
    return false;
}

void Consumer::onEndCollisionWith(Particle& particle)
{
}

void Consumer::loseHealth()
{
    if (m_health > 0) {
        m_health--;
    }
}

int Consumer::setSpeed(int speed)
{
    int framerate = GameWindow::instance().getFramerate();
    m_speed = speed > framerate ? framerate : speed;
    m_speed = speed < 10 ? 10 : speed;
    m_moveCounter = TurnCounter(framerate / m_speed);
    return m_speed;
}

void Consumer::setHealthRate(int rate)
{
    m_healthCounter = TurnCounter(rate);
}

int Consumer::askGold() const
{
    return m_gold;
}

bool Consumer::exists() const
{
    return m_health > 0;
}

void Consumer::move()
{
    if (m_moveCounter.update()) {
        m_position = Positioner::instance().nextRandGoal(m_position, m_goal);
    }
}

void Consumer::render()
{
    CircleShape circle(m_size);
    if (m_hasCollision) {
        circle.setFillColor(Color::Red);
    } else {
        circle.setFillColor(Color(0, 0, 255 * ((float)m_health / m_original_health)));
    }
    circle.setPosition(m_position);
    GameWindow::instance().render(circle);

    Text text = TextCreator::instance().createDialog(to_string(m_gold));
    text.setPosition(m_position);
    text.setCharacterSize(m_size * 8);
    GameWindow::instance().render(text);
}

bool Consumer::collidesWith(const Particle& particle)
{
    const Vector2f& otherPosition = particle.getPosition();
    Vector2f diff = otherPosition - m_position;
    float combinedRadius = m_size + particle.getSize();
    float combinedRadiusSquared = combinedRadius * combinedRadius;
    float squaredDistance = diff.x * diff.x + diff.y * diff.y;
    return squaredDistance <= combinedRadiusSquared;
}

void Consumer::eat(int amount)
{
    m_food -= amount;
    m_health += amount * 5;
}

void Consumer::setGold(int quantity)
{
    m_gold += quantity;
}

bool Consumer::isHealthy()
{
    return (float)m_health / m_original_health > 0.3;
}

void Consumer::tick()
{
    m_hasCollision = m_colliders.empty() ? false : true;
    if (m_healthCounter.update()) {
        loseHealth();
        if (!isHealthy() && m_food > 0) {
            eat(1);
        }
        if (m_health < m_original_health) {
            setSpeed(m_speed * (float)m_health / m_original_health);
        }
    }
}
