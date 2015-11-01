#include <SFML/Graphics/CircleShape.hpp>

#include "monster.h"
#include "gameWindow.h"
#include "positioner.h"

using namespace sf;

void Monster::setPosition(const Vector2f& position)
{
    m_position = position;
}

void Monster::randomWalk()
{
    m_position = Positioner::instance().next(m_position);
}

void Monster::render()
{
    CircleShape circle(10.f);
    circle.setFillColor(Color::Blue);
    circle.setPosition(m_position);
    GameWindow::instance().render(circle);
}
