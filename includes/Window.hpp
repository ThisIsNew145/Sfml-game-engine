#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Window.hpp>

typedef struct{
  sf::RenderWindow app;
} Window;

extern sf::RectangleShape rect;

void CreateWindow(Window* window, int width, int height, std::string& title);
void Loop(Window* window, sf::Event event);
void Draw(Window* window);
void Input(Window* window);
