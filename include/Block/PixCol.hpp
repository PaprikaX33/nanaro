#ifndef NANARO_BLOCK_PIXCOL_HEAD_HPP
#define NANARO_BLOCK_PIXCOL_HEAD_HPP
#include <cstdint>

namespace Block {
  enum class Colour : std::uint8_t {
                                   WHITE,
                                   BLACK,
                                   RED,
                                   GREEN,
                                   BLANK = WHITE
  };
}

#endif //NANARO_BLOCK_PIXCOL_HEAD_HPP
