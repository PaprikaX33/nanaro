#ifndef NANARO_GRID_TYPE_HEAD_HPP
#define NANARO_GRID_TYPE_HEAD_HPP
#include <array>
#include <cstddef>

namespace Grid {
  namespace Wall{
    //Map is 16x16, but the usable size is 14x14 as the most outer side is for wall
    //Therefore the layout is only 14x14
    constexpr std::size_t layoutSize = 14u * 14u;
    using Layout = std::array<bool, layoutSize>; //An array of wall or not
    Grid::Wall::Layout const & get_random_layout(void); //get random layout
    //TODO: get a controlable layout
    }
}

#endif //NANARO_GRID_TYPE_HEAD_HPP
