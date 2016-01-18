#include "resource.h"

#include <string>

using namespace sf;
using namespace std;

Resource::Resource(float size, float value) :
    Particle(size, value)
{
}

void Resource::render()
{
    CircleShape circle(m_size);
    circle.setPosition(m_position);
    circle.setFillColor(Color::Green);
    GameWindow::instance().render(circle);

    Text text = TextCreator::instance().createDialog(to_string((int)m_value));
    text.setPosition(m_position);
    text.setCharacterSize(m_size * 8);
    GameWindow::instance().render(text);
}

void Resource::onBeginCollisionWith(Particle& particle)
{
}

void Resource::onEndCollisionWith(Particle& particle)
{
}

bool Resource::collidesWith(const Particle& particle)
{
    const Vector2f& otherPosition = particle.getPosition();
    Vector2f diff = otherPosition - m_position;
    float combinedRadius = m_size + particle.getSize();
    float combinedRadiusSquared = combinedRadius * combinedRadius;
    float squaredDistance = diff.x * diff.x + diff.y * diff.y;
    return squaredDistance <= combinedRadiusSquared;
}

bool Resource::isResource() const
{
    return true;
}

bool Resource::exists() const
{
    return m_value > 0;
}

void Resource::consume(int amount)
{
    m_value -= amount;
    float new_size = m_original_size * (m_value / m_original_value);
    if (new_size > 2) {
        m_size = new_size;
    }
}
