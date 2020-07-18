#include "Grid/Wall.hpp"
#include "Grid/Opening.hpp"
#include "System/Random.hpp"
#include <cstdint>

enum class OpPoss : std::uint_least8_t {
                                        TOP,
                                        RGH,
                                        BOT,
                                        LFT
};

static void create_openings(enum Block::Type * arr, enum OpPoss pos);

void Grid::Border::draw(enum Block::Type * arr, Grid::Border::Type type)
{
  for(std::size_t i = 0; i < 16u; i++){
    switch(sys::rng::wall()){
    default:
    case 0: arr[i] = Block::Type::WALL_A; break;
    case 1: arr[i] = Block::Type::WALL_B; break;
    case 2: arr[i] = Block::Type::WALL_C; break;
    case 3: arr[i] = Block::Type::WALL_D; break;
    }
    switch(sys::rng::wall()){
    default:
    case 0: arr[(15*16)+i] = Block::Type::WALL_A; break;
    case 1: arr[(15*16)+i] = Block::Type::WALL_B; break;
    case 2: arr[(15*16)+i] = Block::Type::WALL_C; break;
    case 3: arr[(15*16)+i] = Block::Type::WALL_D; break;
    }
  }
  for(std::size_t i = 1; i < 15u; i++){
    switch(sys::rng::wall()){
    default:
    case 0: arr[16*i] = Block::Type::WALL_A; break;
    case 1: arr[16*i] = Block::Type::WALL_B; break;
    case 2: arr[16*i] = Block::Type::WALL_C; break;
    case 3: arr[16*i] = Block::Type::WALL_D; break;
    }
    switch(sys::rng::wall()){
    default:
    case 0: arr[(i*16)+15] = Block::Type::WALL_A; break;
    case 1: arr[(i*16)+15] = Block::Type::WALL_B; break;
    case 2: arr[(i*16)+15] = Block::Type::WALL_C; break;
    case 3: arr[(i*16)+15] = Block::Type::WALL_D; break;
    }
  }
  if(type.x.x) {
    create_openings(arr, OpPoss::TOP);
  }
  if(type.x.y) {
    create_openings(arr, OpPoss::BOT);
  }
  if(type.y.y) {
    create_openings(arr, OpPoss::RGH);
  }
  if(type.y.x) {
    create_openings(arr, OpPoss::LFT);
  }
  return;
}

void create_openings(enum Block::Type * arr, enum OpPoss pos)
{
  for(std::size_t i = 0u; i < 2u; i++){
    switch(pos){
    default:
    case OpPoss::TOP: arr[7+i] = Block::Type::BLANK; break;
    case OpPoss::RGH: arr[16*(i+7)+15] = Block::Type::BLANK; break;
    case OpPoss::BOT: arr[(15*16)+7+i] = Block::Type::BLANK; break;
    case OpPoss::LFT: arr[16*(i+7)] = Block::Type::BLANK; break;
    }
  }
}
