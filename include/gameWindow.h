#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class GameWindow 
{
private:
    sf::RenderWindow* m_window;
    int m_scale;

    GameWindow(int width, int height, int scale);
    ~GameWindow();

    GameWindow(GameWindow const&) = delete;
    void operator=(GameWindow const&)  = delete;

public:
    static GameWindow& instance();
    void render(sf::CircleShape& shape);
    sf::RenderWindow* getWindow();
};

#endif /* WINDOW_H */
