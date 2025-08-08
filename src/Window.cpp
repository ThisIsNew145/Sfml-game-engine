#include "../includes/Window.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>

void CreateWindow(Window* window, int width, int height, std::string& title){
  window->app.create(sf::VideoMode(width, height), title.c_str());
}

void Loop(Window* window, sf::Event event){
  while (window->app.isOpen()){
    while (window->app.pollEvent(event)){
      if (event.type == sf::Event::Closed)
        window->app.close();
    }

    window->app.clear(sf::Color::White);
    Input(window);
    Draw(window);
    window->app.display();
  }
}

void Input(Window *window){
}

void Draw(Window *window){
  sf::RectangleShape rect;
  rect.setSize(sf::Vector2(100.f, 100.0f));
  rect.setFillColor(sf::Color(100, 100, 100, 255));
  window->app.draw(rect);
}
