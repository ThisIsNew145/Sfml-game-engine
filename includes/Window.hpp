#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Window.hpp>

typedef struct{
  sf::RenderWindow app;
} Window;

extern sf::Texture tex;
extern sf::Sprite sprite;
extern sf::Texture mapTex;
extern sf::Sprite mapSprite;

void CreateWindow(Window* window, int width, int height, std::string& title);
void Loop(Window* window, sf::Event event);
void Draw(Window* window);
void Input(Window* window);
