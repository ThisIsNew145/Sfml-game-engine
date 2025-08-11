#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#define TILE_WIDTH 64
#define TILE_HEIGHT 64

struct TileType {
 
  sf::Texture texture;
  bool collidable;
};

struct Map {
  int width, height;
  std::vector<std::vector<int>> data; // Tile IDs
  std::vector<TileType> tileTypes;    // All possible tile types
};

void InitTileTypes(Map* map);
bool IsTileCollidable(Map* map, int tileX, int tileY);
bool LoadMapFromFile(Map& map, const std::string& filename);
void DrawMap(sf::RenderWindow& window, const Map& map);

#endif

