#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class GameWindow 
{
private:
    sf::RenderWindow* m_window;
    int m_width;
    int m_height;
    int m_scale;

    GameWindow();
    ~GameWindow();

    GameWindow(GameWindow const&) = delete;
    void operator=(GameWindow const&)  = delete;

public:
    static GameWindow& instance();
    void open();
    void setWidth(int width);
    void setHeight(int height);
    void setScale(int scale);
    void render(sf::CircleShape& shape);
    sf::RenderWindow* getWindow();
};

#endif /* WINDOW_H */
