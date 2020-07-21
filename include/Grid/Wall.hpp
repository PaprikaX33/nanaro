#ifndef NANARO_GRID_WALL_HEAD_HPP
#define NANARO_GRID_WALL_HEAD_HPP
#include "Grid/Opening.hpp"
#include "Block/Type.hpp"

namespace Grid {
  namespace Border {
    void draw(enum Block::Type * arr, Grid::Border::Type type); //Game block arr(256)
  }
}

#endif //NANARO_GRID_WALL_HEAD_HPP
