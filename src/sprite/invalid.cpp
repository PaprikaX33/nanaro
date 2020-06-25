#include "Sprite/Invalid.hpp"
#include "Sprite/Properties.hpp"
#include "Block/PixCol.hpp"

using Sprite::arr_loc;

void Sprite::draw_invalid(Block::Colour * arr)
{
  for(std::size_t i = 0; i < 12; i++){
    arr[arr_loc(i,0)] = Block::Colour::BLANK;
    arr[arr_loc(i,11)] = Block::Colour::BLANK;
  }
  for(std::size_t i = 1; i < 11; i++){
    arr[arr_loc(0,i)] = Block::Colour::BLANK;
    arr[arr_loc(11,i)] = Block::Colour::BLANK;
  }
  for(std::size_t i = 2; i < 10; i++){
    for(std::size_t o = 2; o < 10; o++){
      arr[arr_loc(i,o)] = Block::Colour::GREEN;
    }
  }
}
