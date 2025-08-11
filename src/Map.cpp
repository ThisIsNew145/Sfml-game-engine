#include "../includes/Map.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void InitTileTypes(Map* map) {
    map->tileTypes[0].collidable = false; // empty
    map->tileTypes[1].collidable = true;  // tree
    map->tileTypes[1].texture.loadFromFile("assets/tree.png");
}

bool IsTileCollidable(Map* map, int tileX, int tileY) {
    int tileID = map->data[tileY][tileX];
    return map->tileTypes[tileID].collidable;
}


bool LoadMapFromFile(Map& map, const std::string& filename) {
   
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Failed to open map file: " << filename << "\n";
    return false;
  }

  std::string line;
  std::vector<std::vector<int>> tempData;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::vector<int> row;
    int tileID;
    while (ss >> tileID) {
      row.push_back(tileID);
    }
    tempData.push_back(row);
  }

 
  map.height = tempData.size();
  map.width = tempData[0].size();
  map.data = tempData;

  // Load tile types (ID -> texture + collidable)
  map.tileTypes.resize(2); // Example: 0 empty, 1 tree
  return true;
}

void DrawMap(sf::RenderWindow& window, const Map& map) {
 
  sf::Sprite sprite;
  
  for (int y = 0; y < map.height; y++) {
    
    for (int x = 0; x < map.width; x++) {
   
      int tileID = map.data[y][x];
      if (tileID == 0) continue; // empty, skip
      sprite.setTexture(map.tileTypes[tileID].texture);
      sprite.setPosition(x * TILE_WIDTH, y * TILE_HEIGHT);
      window.draw(sprite);
    }   
  }
}

