#include "../includes/Window.hpp"
#include "../includes/Grid.hpp"

int main() {
    Window window;
    sf::Event event;
    std::string title = "Game engine";
    CreateWindow(&window, 832, 640, title);

    Map gameMap;
    if (!LoadMapFromFile(gameMap, "maps/test.map")) {
        return 1;
    }

    while (window.app.isOpen()) {
        while (window.app.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.app.close();
        }
        window.app.clear(sf::Color::Black);
        DrawMap(window.app, gameMap);
        window.app.display();
    }
}

