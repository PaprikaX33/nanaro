#ifndef NANARO_PLAYER_PROPERTIES_HEAD_HPP
#define NANARO_PLAYER_PROPERTIES_HEAD_HPP
#include "System/Pair.hpp"
#include "System/Direction.hpp"

namespace Ply {
  struct Player{
    sys::Pairf pos;
    enum sys::Dir direction;
  };
}

#endif //NANARO_PLAYER_PROPERTIES_HEAD_HPP
