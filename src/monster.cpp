#include <SFML/Graphics/CircleShape.hpp>

#include "monster.h"
#include "gameWindow.h"
#include "positioner.h"

using namespace sf;

Monster::Monster(int size) : 
    m_size(size),
    m_turnCount(0),
    m_goal(Positioner::instance().generateGoal())
{
}

void Monster::setPosition(const Vector2f& position)
{
    m_position = position;
}

void Monster::setSpeed(int speed)
{
    int framerate = GameWindow::instance().getFramerate();
    m_speed = speed  > framerate ? framerate : speed;
    m_turnMax = framerate / m_speed;
}

bool Monster::checkTurn()
{
    bool res = false;
    if (++m_turnCount == m_turnMax) {
        m_turnCount = 0;
        res = true; 
    }
    return res;
}

void Monster::move()
{
    if (checkTurn()) {
        m_position = Positioner::instance().nextRandGoal(m_position, m_goal);
    } 
}

void Monster::render()
{
    CircleShape circle(m_size);
    circle.setFillColor(Color::Blue);
    circle.setPosition(m_position);
    GameWindow::instance().render(circle);
}
