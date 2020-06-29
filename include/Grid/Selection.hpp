#ifndef NANARO_GRID_GET_HEAD_HPP
#define NANARO_GRID_GET_HEAD_HPP
#include "Block/Type.hpp"
#include <tuple>

namespace Grid {
  Block::Type const * get(std::pair<int,int> const &);
}


#endif //NANARO_GRID_GET_HEAD_HPP
