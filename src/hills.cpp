#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "gameWindow.h"
#include "config.h"
#include "game.h"

using namespace sf;

int main(int argc, char* argv[]) {
    RenderWindow* window = GameWindow::instance().getWindow();

    window->setFramerateLimit(60);

    Config config;
    Game game;
    game.configure(config);
    game.start();

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
