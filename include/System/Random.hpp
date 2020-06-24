#ifndef NANARO_SYSTEM_RANDOM_HEAD_HPP
#define NANARO_SYSTEM_RANDOM_HEAD_HPP
#include <cstddef>

namespace sys {
  namespace rng {
    // TODO : Set the get and maybe initializer for random. Could also be a class with static function
    void init(void);
    std::size_t wall(void); // 0 <= x < 4
  }
}

#endif //NANARO_SYSTEM_RANDOM_HEAD_HPP
