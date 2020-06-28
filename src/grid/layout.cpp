#include "Grid/Layout.hpp"
#include "System/Random.hpp"
#include <utility>
#include <iostream>

Grid::LocSet Grid::generate_layout(std::size_t count)
{
  Grid::LocSet used;
  Grid::LocSet available;
  used.insert(std::make_pair(0,0));
  available.insert(std::make_pair(-1,0));
  available.insert(std::make_pair(1,0));
  available.insert(std::make_pair(0,-1));
  available.insert(std::make_pair(0,1));
  for(std::size_t i = 0; i < count; i++) {
    auto itr = available.begin();
    auto const loc = sys::rng::general_set(available.size());
    std::advance(itr, loc);
    used.insert(*itr);
    auto const up = std::make_pair(itr->first, itr->second - 1);
    auto const left = std::make_pair(itr->first - 1, itr->second);
    auto const down = std::make_pair(itr->first, itr->second + 1);
    auto const right = std::make_pair(itr->first + 1, itr->second);
    if(!used.count(up)){
      available.insert(up);
    }
    if(!used.count(left)){
      available.insert(left);
    }
    if(!used.count(down)){
      available.insert(down);
    }
    if(!used.count(right)){
      available.insert(right);
    }
    available.erase(itr);
  }
  return used;
}
