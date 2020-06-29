#include "Block/Numeric.hpp"

Block::Type Block::to_sprite(std::size_t val)
{
  switch(val){
    //NUMBERS
  case 0 : return Block::Type::ZERO;
  case 1 : return Block::Type::ONE;
  case 2 : return Block::Type::TWO;
  case 3 : return Block::Type::THREE;
  case 4 : return Block::Type::FOUR;
  case 5 : return Block::Type::FIVE;
  case 6 : return Block::Type::SIX;
  case 7 : return Block::Type::SEVEN;
  case 8 : return Block::Type::EIGHT;
  case 9 : return Block::Type::NINE;
  default: return Block::Type::INVALID;
  }
}
