#ifndef NANARO_GRID_TYPE_HEAD_HPP
#define NANARO_GRID_TYPE_HEAD_HPP
#include <array>

namespace Grid {
  using GridWallLayout = std::array<bool, 256u>; //An array of wall or not
  void initialize(void); //An initialize function for the handwritten walling pattern
  GridWallLayout const & get_wall_layout(void) //get random layout
  //TODO: get a controlable layout
}

#endif //NANARO_GRID_TYPE_HEAD_HPP
