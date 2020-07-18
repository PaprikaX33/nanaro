#ifndef NANARO_GRID_TYPE_HEAD_HPP
#define NANARO_GRID_TYPE_HEAD_HPP
#include <cstdint>

namespace Grid {
  namespace Border {
    //type : 4 bit wasd. true = opening, false = wallled
    using Type = std::uint_least8_t;
  }
}

#endif //NANARO_GRID_TYPE_HEAD_HPP
