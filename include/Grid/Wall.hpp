#ifndef NANARO_GRID_WALL_HEAD_HPP
#define NANARO_GRID_WALL_HEAD_HPP
//#include "Grid/Type.hpp"
#include "Block/Type.hpp"
#include <cstdint>

namespace Grid {
  namespace Border {
    //type : 4 bit wasd. true = opening, false = wallled
    void draw(enum Block::Type * arr, std::uint_least8_t  type); //Game block arr(256)
  }
}

#endif //NANARO_GRID_WALL_HEAD_HPP
