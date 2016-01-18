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

Consumer::Consumer(float size) :
    Particle(size, 0),
    m_hasCollision(false),
    m_gold(0),
    m_health(15),
    m_goal(Positioner::instance().generateGoal())
{
}

Consumer::~Consumer()
{
}

void Consumer::onBeginCollisionWith(Particle& particle)
{
    if (particle.isResource()) {
        Resource& resource = dynamic_cast<Resource&>(particle);
        resource.consume(1);
        m_health += 5;
    }
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

void Consumer::setSpeed(int speed)
{
    int framerate = GameWindow::instance().getFramerate();
    m_speed = speed  > framerate ? framerate : speed;
    m_moveCounter = TurnCounter(framerate / m_speed);
}

void Consumer::setGold(int gold)
{
    m_gold = gold;
}

void Consumer::giveGold(int gold)
{
    m_gold += gold;
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
        circle.setFillColor(Color::Blue);
    }
    circle.setPosition(m_position);
    GameWindow::instance().render(circle);

    Text text = TextCreator::instance().createDialog(to_string(m_health));
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

void Consumer::tick() 
{
    m_hasCollision = m_colliders.empty() ? false : true;
    if (m_healthCounter.update()) {
        loseHealth();
    }
}
