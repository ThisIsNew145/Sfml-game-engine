#include "../includes/Window.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cstdio>

sf::Texture tex;
sf::Sprite sprite;

void CreateWindow(Window* window, int width, int height, std::string& title){
  window->app.create(sf::VideoMode(width, height), title.c_str());
}

void Loop(Window* window, sf::Event event){
  while (window->app.isOpen()){
    while (window->app.pollEvent(event)){
      if (event.type == sf::Event::Closed)
        window->app.close();
    }

    window->app.clear(sf::Color::Black);
    Input(window);
    Draw(window);
    window->app.display();
  }
}

void Input(Window *window){
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    sprite.move(0, -1);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    sprite.move(0, +1);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    sprite.move(-1, 0);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    sprite.move(+1, 0);
}

void Draw(Window *window){
  if (!tex.loadFromFile("assets/Unnamed pokie ball.png")) { printf("The texture could not load"); exit(0);}
  sprite.setTexture(tex);
  window->app.draw(sprite);
}
