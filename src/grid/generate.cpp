#include "Grid/Layout.hpp"
#include "Grid/Type.hpp"
#include "Grid/Properties.hpp"
#include "Grid/Wall.hpp"
#include "Grid/Generate.hpp"
#include "Block/Type.hpp"
#include "Block/Numeric.hpp"
#include <cstdint>
#include <cstddef>

static std::uint_least8_t get_border_type(std::pair<int,int> const &, Grid::LocSet const &);

void Grid::generate_grid(std::size_t count)
{
  auto const layout = Grid::generate_layout(count + 1);
  for(auto const & position : layout) {
    std::array<Block::Type, Grid::gameArrSize> mainArr;
    auto const borderType = get_border_type(position, layout);
    mainArr[16u+13] = Block::to_sprite(static_cast<std::size_t>(position.first < 0 ? position.first * (-1) : position.first));
    mainArr[16u+14] = Block::to_sprite(static_cast<std::size_t>(position.second < 0 ? position.second * (-1) : position.second));
    mainArr[2u*16u+13] = position.first < 0 ? Block::Type::RED : Block::Type::GREEN;
    mainArr[2u*16u+14] = position.second < 0 ? Block::Type::RED : Block::Type::GREEN;
    Grid::Border::draw(mainArr.data(), borderType);
    Grid::textureMap[position] = mainArr;
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
