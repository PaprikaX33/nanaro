#include "Grid/Selection.hpp"
#include "Grid/Properties.hpp"


Block::Type const * Grid::get(std::pair<int,int> const & pos)
{
  if(Grid::textureMap.count(pos)){
    return Grid::textureMap[pos].data();
  }
  else {
    return nullptr;
  }
}

Block::Type const * Grid::get(void)
{
  if(Grid::textureMap.count(Grid::screenPos)){
    return Grid::textureMap[Grid::screenPos].data();
  }
  else {
    return nullptr;
  }
}

std::map<std::pair<int,int>, std::array<Block::Type, Grid::gameArrSize>> Grid::textureMap;
std::pair<int,int> Grid::screenPos = std::pair<int,int>{0,0};
