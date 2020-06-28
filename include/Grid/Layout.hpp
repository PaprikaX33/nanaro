#ifndef NAANRO_GRID_LAYOUT_HEAD_HPP
#define NAANRO_GRID_LAYOUT_HEAD_HPP
#include <tuple>
#include <set>
#include <cstddef>

namespace Grid {
  using LocSet = std::set<std::pair<int, int>>;
  Grid::LocSet generate_layout(std::size_t count); //Count is the number of the side grid
}

#endif //NAANRO_GRID_LAYOUT_HEAD_HPP
