#include "Block/PixCol.hpp"
#include "Block/Colour.hpp"

sf::Color Block::to_colour(enum Block::Colour col)
{
  switch(col){
  case Block::Colour::WHITE:
    return sf::Color(170, 166, 161, 255);
  case Block::Colour::BLACK:
    return sf::Color(0,0,0, 255);
  case Block::Colour::RED:
    return sf::Color(210, 121, 121, 255);
  case Block::Colour::GREEN:
    return sf::Color(121, 210, 121, 255);
  }
  return sf::Color(0,0,0, 255);
}
