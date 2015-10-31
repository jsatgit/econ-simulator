#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics/RenderWindow.hpp>

class GameWindow 
{
private:
    sf::RenderWindow* m_window;

    GameWindow();
    ~GameWindow();

    GameWindow(GameWindow const&) = delete;
    void operator=(GameWindow const&)  = delete;

public:
    static GameWindow& instance();
    void render(const sf::Drawable& drawable);
    sf::RenderWindow* getWindow();
};

#endif /* WINDOW_H */
