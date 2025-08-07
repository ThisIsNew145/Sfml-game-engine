#include "../includes/Window.hpp"
#include <SFML/Window/VideoMode.hpp>

void CreateWindow(Window* window, int width, int height, std::string title){
  window->app.create(sf::VideoMode(width, height), title.c_str());
}

void Loop(Window* window, sf::Event* event){
  while (window->app.isOpen()){
    while (window->app.pollEvent(*event)){
      if (event->type == sf::Event::Closed)
        window->app.close();
    }
    Input(window);
    Draw(window);
  }
}

void Input(Window *window){
}

void Draw(Window *window){
}
