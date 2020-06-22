#include "Block/PixCol.hpp"
#include "Block/Colour.hpp"

sf::Color Block::toColor(enum Block::Color col)
{
  switch(col){
  case Block::Color::WHITE:
    return sf::Color(169, 166, 162, 255);
  case Block::Color::BLACK:
    return sf::Color(0,0,0, 255);
  case Block::Color::RED:
    return sf::Color(210, 121, 121, 255);
  case Block::Color::GREEN:
    return sf::Color(121, 210, 121, 255);
  }
  return sf::Color(0,0,0, 255);
}
