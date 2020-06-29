#include "Grid/Layout.hpp"
#include "Grid/Type.hpp"
#include "Grid/Properties.hpp"
#include "Grid/Wall.hpp"
#include "Grid/Generate.hpp"
#include "Block/Type.hpp"
#include "Block/Numeric.hpp"
#include "System/Random.hpp"
#include <cstdint>
#include <cstddef>
#include <utility>

static std::uint_least8_t get_border_type(std::pair<int,int> const &, Grid::LocSet const &);
static void set_final_location(void);

void Grid::generate_grid(std::size_t count)
{
  Grid::textureMap.clear();
  auto const layout = Grid::generate_layout(count + 1);
  for(auto const & position : layout) {
    std::array<Block::Type, Grid::gameArrSize> mainArr;
    auto const borderType = get_border_type(position, layout);
    for(auto & u : mainArr) {
      u = Block::Type::BLANK;
    }
    mainArr[16u+13] = Block::to_sprite(static_cast<std::size_t>(position.first < 0 ? position.first * (-1) : position.first));
    mainArr[16u+14] = Block::to_sprite(static_cast<std::size_t>(position.second < 0 ? position.second * (-1) : position.second));
    mainArr[2u*16u+13] = position.first < 0 ? Block::Type::RED : Block::Type::GREEN;
    mainArr[2u*16u+14] = position.second < 0 ? Block::Type::RED : Block::Type::GREEN;
    mainArr[8u*16u+8] = Block::Type::WALL_A;
    Grid::Border::draw(mainArr.data(), borderType);
    Grid::textureMap[position] = mainArr;
  }
  set_final_location();
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

void set_final_location(void)
{
  auto iter = Grid::textureMap.begin();
  do {
    std::advance(iter, sys::rng::general_set(Grid::textureMap.size()));
  } while(iter->first.first == 0 && iter->first.second == 0);
  iter->second[7u*16u+7u] = Block::Type::EXIT_UNLOCKED;
}
