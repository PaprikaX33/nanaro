#include "Block/Type.hpp"
#include "Block/PixCol.hpp"
#include "Block/Colour.hpp"
#include "Block/Image.hpp"
#include "Sprite/Init.hpp"
#include "Sprite/Draw.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <cstddef>
#include <unordered_map>

static constexpr std::size_t arrSize = 12u * 12u;
static std::unordered_map<enum Block::Type, sf::Texture> textureMap(76);

void reset_col(Block::Colour *);

void Sprite::initialize(void)
{
  Block::Colour arr[arrSize];
  sf::Texture texture;
  //OPAQUE_WHITE
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  textureMap[Block::Type::OPAQUE_WHITE] = texture;
  //OPAQUE_BLACK
  for(std::size_t i = 0; i < arrSize; i++){
    arr[i] = Block::Colour::BLACK;
  }
  texture.loadFromImage(Block::to_image(arr));
  textureMap[Block::Type::OPAQUE_BLACK] = texture;
  //OPAQUE_RED
  for(std::size_t i = 0; i < arrSize; i++){
    arr[i] = Block::Colour::RED;
  }
  texture.loadFromImage(Block::to_image(arr));
  textureMap[Block::Type::OPAQUE_RED] = texture;
  //OPAQUE_GREEN
  for(std::size_t i = 0; i < arrSize; i++){
    arr[i] = Block::Colour::GREEN;
  }
  texture.loadFromImage(Block::to_image(arr));
  textureMap[Block::Type::OPAQUE_GREEN] = texture;

  //WALL_A
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  textureMap[Block::Type::WALL_A] = texture;
  //WALL_B
  //WALL_C
  //WALL_D
  //EXIT_LOCKED
  //EXIT_UNLOCKED
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

void reset_col(Block::Colour * col)
{
  for(std::size_t i = 0; i < arrSize; i++){
    col[i] = Block::Colour::WHITE;
  }
}
