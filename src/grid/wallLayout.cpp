#include "Grid/WallLayout.hpp"
#include "System/Random.hpp"
#include <set>

static std::set<Grid::Wall::Layout> gridLayout{{0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
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
                                                },
                                               {0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                                                0,0,0,1,1,1,1, 1,1,1,1,1,0,0,
                                                0,0,0,0,0,0,0, 1,0,0,0,1,0,0,
                                                0,0,0,0,0,0,0, 1,0,0,0,1,0,0,
                                                0,0,0,0,0,0,0, 0,0,0,0,1,0,0,
                                                0,0,0,0,0,0,0, 0,0,0,0,1,0,0,
                                                0,0,0,0,0,0,1, 1,1,1,1,1,0,0,

                                                0,0,0,0,0,0,1, 0,0,0,0,0,0,0,
                                                0,0,0,0,0,0,1, 0,0,0,0,0,0,0,
                                                0,0,0,0,0,1,1, 0,0,0,0,0,0,0,
                                                0,0,0,0,0,1,1, 0,0,0,0,0,0,0,
                                                0,0,0,0,1,0,0, 0,0,0,0,0,0,0,
                                                0,0,0,1,0,0,0, 0,0,0,0,0,0,0,
                                                0,0,0,0,0,0,0, 0,0,0,0,0,0,0
                                               },
                                               {0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                                                0,0,0,0,1,1,1, 1,1,1,0,0,0,0,
                                                0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                                                0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                                                0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                                                0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                                                0,0,0,1,0,0,0, 0,0,0,0,1,0,0,

                                                0,0,0,1,0,0,0, 0,0,0,0,1,0,0,
                                                0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                                                0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                                                0,0,0,0,0,1,0, 0,1,0,0,0,0,0,
                                                0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                                                0,0,0,0,0,0,0, 0,0,0,0,0,0,0,
                                                0,0,0,0,0,0,0, 0,0,0,0,0,0,0
                                               }
};

void Grid::Wall::initialize(void)
{
}

Grid::Wall::Layout const & Grid::Wall::get_random_layout(void)
{
  auto itr = gridLayout.begin();
  auto const loc = sys::rng::general_set(gridLayout.size());
  std::advance(itr, loc);
  return *itr;
}
