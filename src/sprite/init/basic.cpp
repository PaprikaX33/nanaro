#include "Block/Image.hpp"
#include "Sprite/UnitInit.hpp"
#include "Sprite/Properties.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <cstddef>

using Sprite::arr_loc;

static void wall_reset(Block::Colour * arr);
static void set_col(enum Block::Colour * arr, std::size_t x, std::size_t y, enum Block::Colour col);

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
  arr[arr_loc(4,4)] = Block::Colour::WHITE;
  arr[arr_loc(3,3)] = Block::Colour::RED;

  arr[arr_loc(7,6)] = Block::Colour::GREEN;
  arr[arr_loc(8,7)] = Block::Colour::GREEN;
  texture.loadFromImage(Block::to_image(arr));
  textureMap[Block::Type::WALL_B] = texture;
  //WALL_C
  wall_reset(arr);
  arr[arr_loc(2,0)] = Block::Colour::WHITE;
  arr[arr_loc(10,9)] = Block::Colour::RED;
  texture.loadFromImage(Block::to_image(arr));
  textureMap[Block::Type::WALL_C] = texture;
  //WALL_D
  wall_reset(arr);
  arr[arr_loc(7,8)] = Block::Colour::GREEN;
  arr[arr_loc(3,3)] = Block::Colour::WHITE;
  arr[arr_loc(10,2)] = Block::Colour::RED;
  arr[arr_loc(9,3)] = Block::Colour::RED;
  texture.loadFromImage(Block::to_image(arr));
  textureMap[Block::Type::WALL_D] = texture;
}

static void set_exit_col(Block::Colour * arr, Block::Colour col);
void Sprite::Init::exit(Block::Colour * arr)
{
  sf::Texture texture;
  //EXIT_LOCKED
  reset_col(arr);
  set_col(arr, 5, 0, Block::Colour::BLACK);
  set_col(arr, 6, 0, Block::Colour::BLACK);
  set_col(arr, 4, 1, Block::Colour::BLACK);
  set_col(arr, 7, 1, Block::Colour::BLACK);
  set_col(arr, 3, 2, Block::Colour::BLACK);
  set_col(arr, 8, 2, Block::Colour::BLACK);
  set_col(arr, 2, 3, Block::Colour::BLACK);
  set_col(arr, 9, 3, Block::Colour::BLACK);
  set_col(arr, 1, 4, Block::Colour::BLACK);
  set_col(arr, 10, 4, Block::Colour::BLACK);
  set_col(arr, 0, 5, Block::Colour::BLACK);
  set_col(arr, 11, 5, Block::Colour::BLACK);

  set_col(arr, 5, 11, Block::Colour::BLACK);
  set_col(arr, 6, 11, Block::Colour::BLACK);
  set_col(arr, 4, 10, Block::Colour::BLACK);
  set_col(arr, 7, 10, Block::Colour::BLACK);
  set_col(arr, 3, 9, Block::Colour::BLACK);
  set_col(arr, 8, 9, Block::Colour::BLACK);
  set_col(arr, 2, 8, Block::Colour::BLACK);
  set_col(arr, 9, 8, Block::Colour::BLACK);
  set_col(arr, 1, 7, Block::Colour::BLACK);
  set_col(arr, 10, 7, Block::Colour::BLACK);
  set_col(arr, 0, 6, Block::Colour::BLACK);
  set_col(arr, 11, 6, Block::Colour::BLACK);

  set_exit_col(arr, Block::Colour::RED);
  texture.loadFromImage(Block::to_image(arr));
  textureMap[Block::Type::EXIT_LOCKED] = texture;
  //EXIT_UNLOCKED
  set_exit_col(arr, Block::Colour::GREEN);
  texture.loadFromImage(Block::to_image(arr));
  textureMap[Block::Type::EXIT_UNLOCKED] = texture;
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

void set_col(enum Block::Colour * arr, std::size_t x, std::size_t y, enum Block::Colour col)
{
  arr[arr_loc(x,y)] = col;
}

void set_exit_col(Block::Colour * arr, Block::Colour col)
{
  set_col(arr, 5, 1, col);
  set_col(arr, 6, 1, col);

  set_col(arr, 5, 2, col);
  set_col(arr, 6, 2, col);
  set_col(arr, 4, 2, col);
  set_col(arr, 7, 2, col);

  set_col(arr, 5, 3, col);
  set_col(arr, 6, 3, col);
  set_col(arr, 4, 3, col);
  set_col(arr, 7, 3, col);
  set_col(arr, 3, 3, col);
  set_col(arr, 8, 3, col);

  set_col(arr, 5, 4, col);
  set_col(arr, 6, 4, col);
  set_col(arr, 4, 4, col);
  set_col(arr, 7, 4, col);
  set_col(arr, 3, 4, col);
  set_col(arr, 8, 4, col);
  set_col(arr, 2, 4, col);
  set_col(arr, 9, 4, col);

  set_col(arr, 5,  5, col);
  set_col(arr, 6,  5, col);
  set_col(arr, 4,  5, col);
  set_col(arr, 7,  5, col);
  set_col(arr, 3,  5, col);
  set_col(arr, 8,  5, col);
  set_col(arr, 2,  5, col);
  set_col(arr, 9,  5, col);
  set_col(arr, 1,  5, col);
  set_col(arr, 10, 5, col);

  set_col(arr, 5,  6, col);
  set_col(arr, 6,  6, col);
  set_col(arr, 4,  6, col);
  set_col(arr, 7,  6, col);
  set_col(arr, 3,  6, col);
  set_col(arr, 8,  6, col);
  set_col(arr, 2,  6, col);
  set_col(arr, 9,  6, col);
  set_col(arr, 1,  6, col);
  set_col(arr, 10, 6, col);

  set_col(arr, 5, 7, col);
  set_col(arr, 6, 7, col);
  set_col(arr, 4, 7, col);
  set_col(arr, 7, 7, col);
  set_col(arr, 3, 7, col);
  set_col(arr, 8, 7, col);
  set_col(arr, 2, 7, col);
  set_col(arr, 9, 7, col);

  set_col(arr, 5, 8, col);
  set_col(arr, 6, 8, col);
  set_col(arr, 4, 8, col);
  set_col(arr, 7, 8, col);
  set_col(arr, 3, 8, col);
  set_col(arr, 8, 8, col);

  set_col(arr, 5, 9, col);
  set_col(arr, 6, 9, col);
  set_col(arr, 4, 9, col);
  set_col(arr, 7, 9, col);

  set_col(arr, 5, 10, col);
  set_col(arr, 6, 10, col);
}
