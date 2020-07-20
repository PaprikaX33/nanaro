#include "Grid/WallLayout.hpp"
#include "System/Random.hpp"
#include <set>

static std::set<Grid::Wall::Layout> gridLayout;

void Grid::Wall::initialize(void)
{
  gridLayout.insert({0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0, 0,0,0,0,0,0,0,

                     0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0, 0,0,0,0,0,0,0
    });
}

Grid::Wall::Layout const & Grid::Wall::get_random_layout(void)
{
  auto itr = gridLayout.begin();
  auto const loc = sys::rng::general_set(gridLayout.size());
  std::advance(itr, loc);
  return *itr;
}
