#ifndef NANARO_GRID_OPENING_HEAD_HPP
#define NANARO_GRID_OPENING_HEAD_HPP
#include "System/Pair.hpp"

namespace Grid {
  namespace Border {
    //{
    // x : {
    //  x : top;
    //  y : bot;
    // },
    // y : {
    //  x : lft;
    //  y : rgh;
    // }
    //}
    using Type = sys::Pair<sys::Pair<bool>>;
  }
}

#endif //NANARO_GRID_OPENING_HEAD_HPP
