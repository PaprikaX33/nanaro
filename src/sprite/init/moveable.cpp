#include "Block/Image.hpp"
#include "Sprite/UnitInit.hpp"
#include "Sprite/Properties.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <cstddef>

using Sprite::arr_loc;
static void create_player_head(Block::Colour * arr, std::size_t padx, std::size_t pady);

void Sprite::Init::enemy(Block::Colour * arr)
{
  sf::Texture texture;
  //TODO: ENEMY
  //ENEMY_UP
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::ENEMY_UP] = texture;
  //ENEMY_LEFT
  // reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::ENEMY_LEFT] = texture;
  //ENEMY_DOWN
  // reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::ENEMY_DOWN] = texture;
  //ENEMY_RIGHT
  // reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::ENEMY_RIGHT] = texture;
  //ENEMY_HIT
  // reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::ENEMY_HIT] = texture;
}

void Sprite::Init::player(Block::Colour * arr)
{
  sf::Texture texture;
  //PLAYER_UP
  reset_col(arr);
  create_player_head(arr, 4,1);
  for(std::size_t i = 4; i < 8; i++){
    arr[arr_loc(i,5)] = Block::Colour::RED;
  }
  for(std::size_t i = 3; i < 9; i++){
    arr[arr_loc(i,6)] = Block::Colour::RED;
  }
  for(std::size_t i = 2; i < 10; i++){
    arr[arr_loc(i,7)] = Block::Colour::RED;
  }
  for(std::size_t i = 1; i < 11; i++){
    for(std::size_t o = 8; o < 11; o++){
      arr[arr_loc(i,o)] = Block::Colour::RED;
    }
  }
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::PLAYER_UP] = texture;
  //PLAYER_DOWN
  for(std::size_t i = 4; i < 8; i++){
    arr[arr_loc(i,6)] = Block::Colour::GREEN;
  }
  for(std::size_t i = 3; i < 9; i++){
    arr[arr_loc(i,7)] = Block::Colour::GREEN;
  }
  for(std::size_t i = 2; i < 10; i++){
    for(std::size_t o = 8; o < 11; o++){
      arr[arr_loc(i,o)] = Block::Colour::GREEN;
    }
  }
  for(std::size_t i = 6; i < 11; i++){
    arr[arr_loc(5,i)] = Block::Colour::BLACK;
    arr[arr_loc(6,i)] = Block::Colour::BLACK;
  }
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::PLAYER_DOWN] = texture;
  //PLAYER_LEFT
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::PLAYER_LEFT] = texture;
  //PLAYER_RIGHT
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::PLAYER_RIGHT] = texture;
  //PLAYER_HIT
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::PLAYER_HIT] = texture;
}

void create_player_head(Block::Colour * arr, std::size_t x, std::size_t y)
{
  //arr[arr_loc(8,7)] = Block::Colour::BLACK;
  for(std::size_t i = 0; i < 4; i++){
    for(std::size_t o = 0; o < 4; o++){
      arr[arr_loc(x+i,y+o)] = Block::Colour::BLACK;
    }
  }
}
