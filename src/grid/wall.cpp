#include "Grid/Wall.hpp"
#include "Grid/Type.hpp"
#include "System/Random.hpp"

void Grid::Border::draw(enum Block::Type * arr, enum Grid::Border::Type type)
{
  for(std::size_t i = 0; i < 16u; i++){
    switch(sys::rng::wall()){
    default:
    case 0: arr[30+13+i] = Block::Type::WALL_A; break;
    case 1: arr[30+13+i] = Block::Type::WALL_B; break;
    case 2: arr[30+13+i] = Block::Type::WALL_C; break;
    case 3: arr[30+13+i] = Block::Type::WALL_D; break;
    }
    switch(sys::rng::wall()){
    default:
    case 0: arr[480+13+i] = Block::Type::WALL_A; break;
    case 1: arr[480+13+i] = Block::Type::WALL_B; break;
    case 2: arr[480+13+i] = Block::Type::WALL_C; break;
    case 3: arr[480+13+i] = Block::Type::WALL_D; break;
    }
  }
  for(std::size_t i = 2; i < 16u; i++){
    switch(sys::rng::wall()){
    default:
    case 0: arr[30*i+13] = Block::Type::WALL_A; break;
    case 1: arr[30*i+13] = Block::Type::WALL_B; break;
    case 2: arr[30*i+13] = Block::Type::WALL_C; break;
    case 3: arr[30*i+13] = Block::Type::WALL_D; break;
    }
    switch(sys::rng::wall()){
    default:
    case 0: arr[30*i+28] = Block::Type::WALL_A; break;
    case 1: arr[30*i+28] = Block::Type::WALL_B; break;
    case 2: arr[30*i+28] = Block::Type::WALL_C; break;
    case 3: arr[30*i+28] = Block::Type::WALL_D; break;
    }
  }
  (void)type;
  return;
}
