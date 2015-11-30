#include "gameWindow.h"
#include <SFML/System/Vector2.hpp>

using namespace sf;

GameWindow::GameWindow()
{
}

GameWindow::~GameWindow()
{
    delete m_window;
}

GameWindow& GameWindow::instance()
{
    static GameWindow instance;
    return instance;
}

void GameWindow::open()
{
    m_window = new RenderWindow(VideoMode(m_width * m_scale, m_height * m_scale), "hills");
    m_window->setFramerateLimit(m_frameRate);
}

void GameWindow::setWidth(int width)
{
    m_width = width;
}

void GameWindow::setHeight(int height)
{
    m_height = height;
}

void GameWindow::setScale(int scale)
{
    m_scale = scale;
}

void GameWindow::setFramerate(int frameRate)
{
    m_frameRate = frameRate;
}

int GameWindow::getFramerate()
{
    return m_frameRate;
}

int GameWindow::getWidth()
{
    return m_width;
}

int GameWindow::getHeight()
{
    return m_height;
}

void GameWindow::render(CircleShape& circle)
{
    float radius = circle.getRadius();
    const Vector2f& position = circle.getPosition();
    circle.setScale(m_scale, m_scale);
    circle.setOrigin(radius, radius);
    circle.setPosition(circle.getPosition() * (float)m_scale);
    m_window->draw(circle);
}

void GameWindow::render(RectangleShape& rect)
{
    const Vector2f& position = rect.getPosition();
    auto bounds = rect.getLocalBounds();
    rect.setScale(m_scale, m_scale);
    rect.setOrigin(bounds.width/2, bounds.height/2);
    rect.setPosition(position * (float)m_scale);
    m_window->draw(rect);
}

void GameWindow::render(Text& text)
{
    const Vector2f& position = text.getPosition();
    auto bounds = text.getLocalBounds();
    text.setOrigin(bounds.width/2, bounds.height/2);
    text.setPosition(position * (float)m_scale);
    m_window->draw(text);
}

RenderWindow* GameWindow::getWindow()
{
    return m_window;
}
