#include "Grid/Layout.hpp"
#include "Grid/Type.hpp"
#include "Grid/Properties.hpp"
#include "Grid/Generate.hpp"
#include <cstdint>
#include <cstddef>

static std::uint_least8_t get_border_type(std::pair<int,int> const &, Grid::LocSet const &);

void Grid::generate_grid(std::size_t count)
{
  auto const layout = Grid::generate_layout(count + 1);
  for(auto const & position : layout) {
    std::array<Block::Type, Grid::gameArrSize> mainArr;
    auto const borderType = get_border_type(position, layout);
    (void)mainArr;
    (void)borderType;
  }
}


std::uint_least8_t get_border_type(std::pair<int,int> const & pos, Grid::LocSet const & sur)
{
  using keyPair = std::pair<int,int>;
  auto key = [](bool tr, std::size_t offset){
               std::uint_least8_t const bitmask = 0b1111;
               std::uint_least8_t const val = bitmask & ((tr ? 1u : 0u) << offset);
               return val;
             };
  bool const top = sur.count(keyPair{pos.first, pos.second - 1});
  bool const rgh = sur.count(keyPair{pos.first + 1, pos.second});
  bool const bot = sur.count(keyPair{pos.first, pos.second + 1});
  bool const lft = sur.count(keyPair{pos.first - 1, pos.second});
  std::uint_least8_t const cases = key(top, 3) | key(lft, 2) | key(bot, 1) | key(rgh, 0);
  return cases;
}
