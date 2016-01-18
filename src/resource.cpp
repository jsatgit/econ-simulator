#include "resource.h"

#include <string>

using namespace sf;
using namespace std;

Resource::Resource() :
    m_value(100),
    m_size(2)
{
}

void Resource::setPosition(const Vector2f& position)
{
    m_position = position;
}

void Resource::render()
{
    CircleShape circle(m_size);
    circle.setPosition(m_position);
    circle.setFillColor(Color::Green);
    GameWindow::instance().render(circle);

    Text text = TextCreator::instance().createDialog(to_string(m_value));
    text.setPosition(m_position);
    text.setCharacterSize(m_size * 8);
    GameWindow::instance().render(text);
}
