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

void GameWindow::render(CircleShape& shape)
{
    const Vector2f& position = shape.getPosition();
    int radius = shape.getRadius();
    shape.setPosition((position + Vector2f(radius, radius)) * (float)m_scale);
    shape.setRadius(radius * m_scale);
    m_window->draw(shape);
}

void GameWindow::render(Text& text)
{
    text.setOrigin(-3 * m_scale, -3 * m_scale);
    const Vector2f& position = text.getPosition();
    text.setPosition(position * (float)m_scale);
    m_window->draw(text);
}

RenderWindow* GameWindow::getWindow()
{
    return m_window;
}
