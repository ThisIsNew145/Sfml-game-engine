#include "../includes/Window.hpp"

int main (){

  int width = 800;
  int height = 600;
  std::string title = "Game engine";
  Window window;
  sf::Event event;

  CreateWindow(&window, width, height, title);
  Loop(&window, &event);

  return 0;
}
