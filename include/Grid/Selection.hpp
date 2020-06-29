#ifndef NANARO_GRID_SELECTION_HEAD_HPP
#define NANARO_GRID_SELECTION_HEAD_HPP
#include "Block/Type.hpp"
#include <tuple>

namespace Grid {
  Block::Type const * get(std::pair<int,int> const &);
  Block::Type const * get(void);
  //TODO: replace the pair to sys::pair
  extern std::pair<int,int> screenPos;
}


#endif //NANARO_GRID_SELECTION_HEAD_HPP
