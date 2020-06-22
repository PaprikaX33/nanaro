#include "Block/Type.hpp"
#include "Block/PixCol.hpp"
#include "Block/Image.hpp"
#include "Sprite/Init.hpp"
#include "Sprite/Draw.hpp"
#include "Sprite/Properties.hpp"
#include "Sprite/UnitInit.hpp"

void Sprite::initialize(void)
{
  Block::Colour arr[arrSize];
  Sprite::Init::opaque(arr);
  Sprite::Init::wall(arr);
  Sprite::Init::exit(arr);
  //ENEMY_UP
  //ENEMY_LEFT
  //ENEMY_DOWN
  //ENEMY_RIGHT
  //ENEMY_HIT
  //PLAYER_UP
  //PLAYER_LEFT
  //PLAYER_DOWN
  //PLAYER_RIGHT
  //PLAYER_HIT
  //WEAPON_MELEE_UP
  //WEAPON_MELEE_LEFT
  //WEAPON_MELEE_DOWN
  //WEAPON_MELEE_RIGHT
  //WEAPON_RANGE_UP
  //WEAPON_RANGE_LEFT
  //WEAPON_RANGE_DOWN
  //WEAPON_RANGE_RIGHT
  //KEY_BLACK
  //KEY_RED
  //KEY_GREEN
  //KEY_BLACK_RED
  //KEY_BLACK_GREEN
  //KEY_RED_GREEN
  //KEY_GREEN_RED
  //A
  //B
  //C
  //D
  //E
  //F
  //G
  //H
  //I
  //J
  //K
  //L
  //M
  //N
  //O
  //P
  //Q
  //R
  //S
  //T
  //U
  //V
  //W
  //X
  //Y
  //Z
  //ZERO
  //ONE
  //TWO
  //THREE
  //FOUR
  //FIVE
  //SIX
  //SEVEN
  //EIGHT
  //NINE
  //COLON
  //SEMI_COLON
  //DOT
  //COMMA
  //DASH
}

void Sprite::Init::reset_col(Block::Colour * col)
{
  for(std::size_t i = 0; i < Sprite::arrSize; i++){
    col[i] = Block::Colour::WHITE;
  }
}

std::unordered_map<enum Block::Type, sf::Texture> Sprite::textureMap(76);
