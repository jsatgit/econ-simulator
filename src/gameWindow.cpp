#include "gameWindow.h"
#include <SFML/System/Vector2.hpp>

using namespace sf;

GameWindow::GameWindow(int width, int height, int scale) : 
    m_window(new RenderWindow(VideoMode(width * scale, height * scale), "hills")),
    m_scale(scale)
{
}

GameWindow::~GameWindow()
{
    delete m_window;
}

GameWindow& GameWindow::instance()
{
    static GameWindow instance(200, 200, 8);
    return instance;
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
