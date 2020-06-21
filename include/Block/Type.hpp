#ifndef NANARO_BLOCK_TYPE_HEAD_HPP
#define NANARO_BLOCK_TYPE_HEAD_HPP
#include <cstdint>

namespace Block{
  enum class Type : std::uint8_t {
                                  BLANK = WHITE,
                                  BLACK,
                                  RED,
                                  GREEN
  };
}

#endif //NANARO_BLOCK_TYPE_HEAD_HPP
