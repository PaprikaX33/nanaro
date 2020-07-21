#ifndef NANARO_SYSTEM_RANDOM_HEAD_HPP
#define NANARO_SYSTEM_RANDOM_HEAD_HPP
#include <cstddef>

namespace sys {
  namespace rng {
    // TODO : Set the get and maybe initializer for random. Could also be a class with static function
    void init(void);
    std::size_t wall(void); // 0 <= x < 4
    std::size_t general_set(std::size_t max, std::size_t min = 0u); // min <= x < max
  }
}

#endif //NANARO_SYSTEM_RANDOM_HEAD_HPP
