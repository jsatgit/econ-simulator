#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "gameWindow.h"
#include "config.h"
#include "game.h"

#include <iostream>

using namespace sf;
using namespace std;

int main(int argc, char* argv[]) {

    Config config;
    Game game;
    game.configure(config);
    game.start();

    RenderWindow* window = GameWindow::instance().getWindow();

    while (window->isOpen()) {
        Event Event;
        while (window->pollEvent(Event)) {
            if (Event.type == Event::Closed)
                window->close();
        }
        window->clear(Color::Black);

        game.tick();
        game.render();

        window->display();
    }
}
