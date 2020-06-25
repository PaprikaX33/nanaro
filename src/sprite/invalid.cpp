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
  for(std::size_t i = 0; i < 10; i++){
    arr[arr_loc(i+1,1)] = Block::Colour::BLACK;
    arr[arr_loc(1,i+1)] = Block::Colour::BLACK;
    arr[arr_loc(i+1,10)] = Block::Colour::BLACK;
    arr[arr_loc(10,i+1)] = Block::Colour::BLACK;
    arr[arr_loc(i+1,i+1)] = Block::Colour::BLACK;
    arr[arr_loc(i+1,10-i)] = Block::Colour::BLACK;
  }
  for(std::size_t i = 0; i < 3; i++){
    arr[arr_loc(i+2,5)] = Block::Colour::RED;
    arr[arr_loc(i+2,6)] = Block::Colour::RED;
    arr[arr_loc(i+7,5)] = Block::Colour::RED;
    arr[arr_loc(i+7,6)] = Block::Colour::RED;
    arr[arr_loc(5,i+2)] = Block::Colour::RED;
    arr[arr_loc(6,i+2)] = Block::Colour::RED;
    arr[arr_loc(5,i+7)] = Block::Colour::RED;
    arr[arr_loc(6,i+7)] = Block::Colour::RED;
  }
}
