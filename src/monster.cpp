#include <SFML/Graphics/CircleShape.hpp>

#include "monster.h"
#include "gameWindow.h"
#include "positioner.h"

using namespace sf;

void Monster::setPosition(Vector2f position)
{
    m_position = position;
}

void Monster::move()
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
