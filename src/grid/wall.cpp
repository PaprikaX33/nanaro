#include "Grid/Wall.hpp"
#include "Grid/Type.hpp"
#include "System/Random.hpp"
#include <cstdint>

enum class OpPoss : std::uint_least8_t {
                                        TOP,
                                        RGH,
                                        BOT,
                                        LFT
};

static void create_openings(enum Block::Type * arr, enum OpPoss pos);

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
  switch(type) {
  case Grid::Border::Type::TOP_LFT:
    create_openings(arr, OpPoss::RGH);
    create_openings(arr, OpPoss::BOT);
    break;
  case Grid::Border::Type::TOP_CNT:
    create_openings(arr, OpPoss::RGH);
    create_openings(arr, OpPoss::BOT);
    create_openings(arr, OpPoss::LFT);
    break;
  case Grid::Border::Type::TOP_RGH:
    create_openings(arr, OpPoss::BOT);
    create_openings(arr, OpPoss::LFT);
    break;
  case Grid::Border::Type::MID_LFT:
    create_openings(arr, OpPoss::TOP);
    create_openings(arr, OpPoss::RGH);
    create_openings(arr, OpPoss::BOT);
    break;
  case Grid::Border::Type::MID_CNT:
    create_openings(arr, OpPoss::TOP);
    create_openings(arr, OpPoss::RGH);
    create_openings(arr, OpPoss::BOT);
    create_openings(arr, OpPoss::LFT);
    break;
  case Grid::Border::Type::MID_RGH:
    create_openings(arr, OpPoss::TOP);
    create_openings(arr, OpPoss::BOT);
    create_openings(arr, OpPoss::LFT);
    break;
  case Grid::Border::Type::BOT_LFT:
    create_openings(arr, OpPoss::TOP);
    create_openings(arr, OpPoss::RGH);
    break;
  case Grid::Border::Type::BOT_CNT:
    create_openings(arr, OpPoss::TOP);
    create_openings(arr, OpPoss::RGH);
    create_openings(arr, OpPoss::LFT);
    break;
  case Grid::Border::Type::BOT_RGH:
    create_openings(arr, OpPoss::TOP);
    create_openings(arr, OpPoss::LFT);
    break;
  }
  return;
}

void create_openings(enum Block::Type * arr, enum OpPoss pos)
{
  //20,21
  for(std::size_t i = 0u; i < 2u; i++){
    switch(pos){
    default:
    case OpPoss::TOP: arr[30+20+i] = Block::Type::BLANK; break;
    case OpPoss::RGH: arr[30*(i+8)+28] = Block::Type::BLANK; break;
    case OpPoss::BOT: arr[480+20+i] = Block::Type::BLANK; break;
    case OpPoss::LFT: arr[30*(i+8)+13] = Block::Type::BLANK; break;
    }
  }
}
