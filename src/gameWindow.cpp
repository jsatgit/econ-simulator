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

void GameWindow::render(CircleShape& shape)
{
    const Vector2f& position = shape.getPosition();
    shape.setPosition(position.x * m_scale, position.y * m_scale);
    int radius = shape.getRadius();
    shape.setRadius(radius * m_scale);
    m_window->draw(shape);
}

RenderWindow* GameWindow::getWindow()
{
    return m_window;
}
