#include "Block/Image.hpp"
#include "Sprite/UnitInit.hpp"
#include "Sprite/Properties.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <cstddef>

void Sprite::Init::enemy(Block::Colour * arr)
{
  sf::Texture texture;
  //ENEMY_UP
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::ENEMY_UP] = texture;
  //ENEMY_LEFT
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::ENEMY_LEFT] = texture;
  //ENEMY_DOWN
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::ENEMY_DOWN] = texture;
  //ENEMY_RIGHT
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::ENEMY_RIGHT] = texture;
  //ENEMY_HIT
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::ENEMY_HIT] = texture;
}

void Sprite::Init::player(Block::Colour * arr)
{
  sf::Texture texture;
  //PLAYER_UP
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::PLAYER_UP] = texture;
  //PLAYER_LEFT
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::PLAYER_LEFT] = texture;
  //PLAYER_DOWN
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::PLAYER_DOWN] = texture;
  //PLAYER_RIGHT
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::PLAYER_RIGHT] = texture;
  //PLAYER_HIT
  reset_col(arr);
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::PLAYER_HIT] = texture;
}
