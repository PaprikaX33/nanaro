#include "Grid/Get.hpp"
#include "Grid/Properties.hpp"


Block::Type const * Grid::get(std::pair<int,int> const & pos)
{
  if(Grid::textureMap.count(pos))
}


std::map<std::pair<int,int>, std::array<Block::Type, Grid::gameArrSize>> Grid::textureMap;
