#include "Block/Image.hpp"
#include "Sprite/UnitInit.hpp"
#include "Sprite/Properties.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <cstddef>

using Sprite::arr_loc;

static void wall_reset(Block::Colour * arr);

void Sprite::Init::opaque(Block::Colour * arr)
{
  sf::Texture texture;
  //OPAQUE_WHITE
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::OPAQUE_WHITE] = texture;
  //OPAQUE_BLACK
  for(std::size_t i = 0; i < arrSize; i++){
    arr[i] = Block::Colour::BLACK;
  }
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::OPAQUE_BLACK] = texture;
  //OPAQUE_RED
  for(std::size_t i = 0; i < arrSize; i++){
    arr[i] = Block::Colour::RED;
  }
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::OPAQUE_RED] = texture;
  //OPAQUE_GREEN
  for(std::size_t i = 0; i < arrSize; i++){
    arr[i] = Block::Colour::GREEN;
  }
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::OPAQUE_GREEN] = texture;
}

void Sprite::Init::wall(Block::Colour * arr)
{
  sf::Texture texture;
  //WALL_A
  wall_reset(arr);
  texture.loadFromImage(Block::to_image(arr));
  textureMap[Block::Type::WALL_A] = texture;
  //WALL_B
  arr[arr_loc(3,4)] = Block::Colour::RED;
  arr[arr_loc(4,4)] = Block::Colour::RED;
  arr[arr_loc(3,3)] = Block::Colour::RED;

  arr[arr_loc(7,6)] = Block::Colour::GREEN;
  arr[arr_loc(8,7)] = Block::Colour::GREEN;
  texture.loadFromImage(Block::to_image(arr));
  textureMap[Block::Type::WALL_B] = texture;
  //WALL_C
  //WALL_D
}

void Sprite::Init::exit(Block::Colour * arr)
{
  (void)arr;
  //EXIT_LOCKED
  //EXIT_UNLOCKED
}

void wall_reset(Block::Colour * arr)
{
  for(std::size_t i = 0; i < Sprite::arrSize; i++){
    arr[i] = Block::Colour::BLACK;
  }
  arr[arr_loc(0,0)] = Block::Colour::WHITE;
  arr[arr_loc(1,0)] = Block::Colour::WHITE;
  arr[arr_loc(0,1)] = Block::Colour::WHITE;
  arr[arr_loc(1,1)] = Block::Colour::WHITE;

  arr[arr_loc(10,0)] = Block::Colour::WHITE;
  arr[arr_loc(11,0)] = Block::Colour::WHITE;
  arr[arr_loc(10,1)] = Block::Colour::WHITE;
  arr[arr_loc(11,1)] = Block::Colour::WHITE;

  arr[arr_loc(0,10)] = Block::Colour::WHITE;
  arr[arr_loc(1,10)] = Block::Colour::WHITE;
  arr[arr_loc(0,11)] = Block::Colour::WHITE;
  arr[arr_loc(1,11)] = Block::Colour::WHITE;

  arr[arr_loc(10,10)] = Block::Colour::WHITE;
  arr[arr_loc(11,10)] = Block::Colour::WHITE;
  arr[arr_loc(10,11)] = Block::Colour::WHITE;
  arr[arr_loc(11,11)] = Block::Colour::WHITE;
}
