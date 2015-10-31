#include "gameWindow.h"

using namespace sf;

GameWindow::GameWindow() : 
    m_window(new RenderWindow(VideoMode(800, 600), "hills"))
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

void GameWindow::render(const Drawable& drawable)
{
    m_window->draw(drawable);
}

RenderWindow* GameWindow::getWindow()
{
    return m_window;
}
