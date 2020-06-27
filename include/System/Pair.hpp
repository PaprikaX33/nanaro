#ifndef NAANRO_SYSTEM_PAIR_HEAD_HPP
#define NAANRO_SYSTEM_PAIR_HEAD_HPP
#include <SFML/System/Vector2.hpp>

namespace sys {
  template<typename T>
  struct Pair{
    T x;
    T y;
    constexpr Pair(){}
    constexpr Pair(T const & a, T const & b):
      x{a},
      y{b}
    {}
    operator sf::Vector2<T> () const {
      return sf::Vector2<T>{x,y};
    }
  };
  using Pairf = Pair<float>;
  using Paird = Pair<double>;
}

#endif //NAANRO_SYSTEM_PAIR_HEAD_HPP
