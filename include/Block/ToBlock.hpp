#ifndef NANARO_BLOCK_TO_BLOCK_HEAD_HPP
#define NANARO_BLOCK_TO_BLOCK_HEAD_HPP
#include "Block/Type.hpp"
#include <vector>
#include <algorithm>

namespace Block {
  namespace conv {
    Block::Type num(std::size_t);
    Block::Type chr(char);
    std::vector<Block::Type> str(char const *str);
    template<typename T>
    std::vector<Block::Type> str(T const & str)
    {
      std::vector<Block::Type> buff;
      std::transform(str.begin(), str.end(), std::back_inserter(buff), Block::conv::chr);
      return buff;
    }
  }
}

#endif //NANARO_BLOCK_TO_BLOCK_HEAD_HPP
