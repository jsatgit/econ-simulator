#include <SFML/Graphics/CircleShape.hpp>

#include "hill.h"
#include "gameWindow.h"
#include "positioner.h"

using namespace sf;

Hill::Hill(int radius, int height):
    m_radius(radius), m_height(height) 
{
}

void Hill::setPosition(const Vector2f& position)
{
    m_position = position;
}

void Hill::move()
{
}

void Hill::render()
{
    double radiusIncrement = (double)m_radius / m_height;
    int alpha = 200 / m_height;
    for (int i = 0; i < m_height; ++i) {
        double currentIncrement = radiusIncrement*i;
        double radius = m_radius - currentIncrement; 
        Vector2f position = Vector2f(m_position.x + currentIncrement, m_position.y + currentIncrement);
        CircleShape circle(radius);
        circle.setFillColor(Color(255, 0, 0, alpha));
        circle.setPosition(position);
        GameWindow::instance().render(circle);
    }
}
