#include "Grid/Layout.hpp"
#include "Grid/Properties.hpp"
#include "Grid/Wall.hpp"
#include "Grid/WallLayout.hpp"
#include "Grid/Generate.hpp"
#include "Block/Type.hpp"
#include "Block/ToBlock.hpp"
#include "System/Random.hpp"
#include <cstdint>
#include <cstddef>
#include <utility>

static Grid::Border::Type get_border_type(std::pair<int,int> const &, Grid::LocSet const &);
static void set_final_location(void);
static void set_initial_location(Grid::Border::Type type);

void Grid::generate_grid(std::size_t count)
{
  Grid::textureMap.clear();
  auto const layout = Grid::generate_layout(count + 1);

  auto getRandomWallType = [](void){
                             switch(sys::rng::wall()){
                             default:
                             case 0: return Block::Type::WALL_A;
                             case 1: return Block::Type::WALL_B;
                             case 2: return Block::Type::WALL_C;
                             case 3: return Block::Type::WALL_D;
                             }
                           };

  for(auto const & position : layout) {
    std::array<Block::Type, Grid::gameArrSize> mainArr;
    auto const borderType = get_border_type(position, layout);
    // for(auto & u : mainArr) {
    //   u = Block::Type::BLANK;
    // }
    //mainArr[16u+13] = Block::conv::num(static_cast<std::size_t>(position.first < 0 ? position.first * (-1) : position.first));
    //mainArr[16u+14] = Block::conv::num(static_cast<std::size_t>(position.second < 0 ? position.second * (-1) : position.second));
    //mainArr[2u*16u+13] = position.first < 0 ? Block::Type::RED : Block::Type::GREEN;
    //mainArr[2u*16u+14] = position.second < 0 ? Block::Type::RED : Block::Type::GREEN;
    //mainArr[8u*16u+8] = Block::Type::WALL_A;
    auto const wallLay = Grid::Wall::get_random_layout();
    for(std::size_t x = 0; x < 14u; x++){
      for(std::size_t y = 0; y < 14u; y++){
        mainArr[x+1+((y+1)*16u)] = wallLay[x+(y*14u)] ? getRandomWallType() : Block::Type::BLANK;
      }
    }

    Grid::Border::draw(mainArr.data(), borderType);
    Grid::textureMap[position] = mainArr;
  }
  set_final_location();
  set_initial_location(get_border_type(std::pair<int,int>{0,0}, layout));
}


Grid::Border::Type get_border_type(std::pair<int,int> const & pos, Grid::LocSet const & sur)
{
  using keyPair = std::pair<int,int>;
  bool const top = sur.count(keyPair{pos.first, pos.second - 1});
  bool const rgh = sur.count(keyPair{pos.first + 1, pos.second});
  bool const bot = sur.count(keyPair{pos.first, pos.second + 1});
  bool const lft = sur.count(keyPair{pos.first - 1, pos.second});
  return Grid::Border::Type{sys::Pair<bool>{top, bot}, sys::Pair<bool>{lft, rgh}};
}

void set_final_location(void)
{
  auto iter = Grid::textureMap.begin();
  do {
    std::advance(iter, sys::rng::general_set(Grid::textureMap.size()));
  } while(iter->first.first == 0 && iter->first.second == 0);
  iter->second[7u*16u+7u] = Block::Type::EXIT_UNLOCKED;
}

void set_initial_location(Grid::Border::Type type)
{
  std::pair<int,int> const initPoint{0,0};
  std::array<Block::Type, Grid::gameArrSize> initForm;
  for(auto & i : initForm){
    i = Block::Type::BLANK;
  }
  Grid::Border::draw(initForm.data(), type);
  Grid::textureMap.at(initPoint) = initForm;
}
