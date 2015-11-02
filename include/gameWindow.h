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
    int m_frameRate;

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
    void setFramerate(int frameRate);
    int getFramerate();
    int getWidth();
    int getHeight();
    void render(sf::CircleShape& shape);
    sf::RenderWindow* getWindow();
};

#endif /* WINDOW_H */
