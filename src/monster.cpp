#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "monster.h"
#include "gameWindow.h"
#include "positioner.h"
#include "textCreator.h"
#include <cmath>

#include <iostream>
#include <string>

using namespace sf;
using namespace std;

Monster::Monster(int size) :
    Particle(size, 0),
    m_hasCollision(false),
    m_gold(0),
    m_health(100),
    m_goal(Positioner::instance().generateGoal())
{
}

void Monster::onBeginCollisionWith(Particle& particle)
{
    m_gold++;
}

void Monster::onEndCollisionWith(Particle& particle)
{
}

void Monster::loseHealth()
{
    if (m_health > 0) {
        m_health--;
    }
}

void Monster::setSpeed(int speed)
{
    int framerate = GameWindow::instance().getFramerate();
    m_speed = speed  > framerate ? framerate : speed;
    m_moveCounter = TurnCounter(framerate / m_speed);
}

void Monster::setGold(int gold)
{
    m_gold = gold;
}

void Monster::giveGold(int gold)
{
    m_gold += gold;
}

void Monster::setHealthRate(int rate)
{
    m_healthCounter = TurnCounter(rate);
}

int Monster::askGold() const
{
    return m_gold;
}

bool Monster::isAlive() const
{
    return m_health > 0;
}

void Monster::move()
{
    if (m_moveCounter.update()) {
        m_position = Positioner::instance().nextRandGoal(m_position, m_goal);
    }
}

void Monster::render()
{
    CircleShape circle(m_size);
    if (m_hasCollision) {
        circle.setFillColor(Color::Red);
    } else {
        circle.setFillColor(Color::Blue);
    }
    circle.setPosition(m_position);
    GameWindow::instance().render(circle);

    Text text = TextCreator::instance().createDialog(to_string(m_health));
    text.setPosition(m_position);
    text.setCharacterSize(m_size * 8);
    GameWindow::instance().render(text);
}

bool Monster::collidesWith(const Particle& particle)
{
    const Vector2f& otherPosition = particle.getPosition();
    Vector2f diff = otherPosition - m_position;
    int combinedRadius = m_size + particle.getSize();
    int combinedRadiusSquared = combinedRadius * combinedRadius;
    int squaredDistance = diff.x * diff.x + diff.y * diff.y;
    return squaredDistance <= combinedRadiusSquared;
}

void Monster::tick() {
    m_hasCollision = m_colliders.empty() ? false : true;
    if (m_healthCounter.update()) {
        loseHealth();
    }
}
