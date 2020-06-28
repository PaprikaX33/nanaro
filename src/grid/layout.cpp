#include "Grid/Layout.hpp"
#include <utility>

Grid::LocSet Grid::generate_layout(std::size_t count)
{
  Grid::LocSet used;
  Grid::LocSet available;
  used.insert(std::make_pair(0,0));
  available.insert(std::make_pair(-1,0));
  available.insert(std::make_pair(1,0));
  available.insert(std::make_pair(0,-1));
  available.insert(std::make_pair(0,1));
  for(std::size_t i = 0; i < count; i++) {

  }
  return used;
}
