#ifndef NANARO_GRID_PROPERTIES_HEAD_HPP
#define NANARO_GRID_PROPERTIES_HEAD_HPP
#include "Block/Type.hpp"
#include <cstddef>
#include <array>
#include <map>

namespace Grid {
  //TODO : GRID OBJECT
  constexpr std::size_t gameArrSize = 16u * 16u;
  extern std::map<std::pair<int,int>, std::array<Block::Type, Grid::gameArrSize>> textureMap;
}

#endif //NANARO_GRID_PROPERTIES_HEAD_HPP
