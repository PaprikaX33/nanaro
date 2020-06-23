#include "Block/Image.hpp"
#include "Sprite/UnitInit.hpp"
#include "Sprite/Properties.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <cstddef>

using Sprite::arr_loc;

void Sprite::Init::num(Block::Colour * arr)
{
  sf::Texture texture;
  //ZERO
  reset_col(arr);
  for(std::size_t i = 3; i < 9; i++){
    arr[arr_loc(2,i)] = Block::Colour::BLACK;
    arr[arr_loc(9,i)] = Block::Colour::BLACK;
  }
  for(std::size_t i = 4; i < 8; i++){
    arr[arr_loc(i,1)] = Block::Colour::BLACK;
    arr[arr_loc(i,10)] = Block::Colour::BLACK;
  }
  for(std::size_t i = 0; i < 2; i++){
    arr[arr_loc(i+3,2)] = Block::Colour::BLACK;
    arr[arr_loc(i+7,2)] = Block::Colour::BLACK;
    arr[arr_loc(i+3,9)] = Block::Colour::BLACK;
    arr[arr_loc(i+7,9)] = Block::Colour::BLACK;
  }
  for(std::size_t i = 3; i < 9; i++){
    arr[arr_loc(i,i)] = Block::Colour::BLACK;
  }
  arr[arr_loc(3,8)] = Block::Colour::BLACK;
  arr[arr_loc(8,3)] = Block::Colour::BLACK;
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::ZERO] = texture;
  //ONE
  reset_col(arr);
  for(std::size_t i = 1; i < 9; i++){
    arr[arr_loc(5,i)] = Block::Colour::BLACK;
    arr[arr_loc(6,i)] = Block::Colour::BLACK;
  }
  for(std::size_t i = 3; i < 9; i++){
    arr[arr_loc(i,9)] = Block::Colour::BLACK;
    arr[arr_loc(i,10)] = Block::Colour::BLACK;
  }
  arr[arr_loc(4,2)] = Block::Colour::BLACK;
  arr[arr_loc(3,3)] = Block::Colour::BLACK;
  arr[arr_loc(4,3)] = Block::Colour::BLACK;
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::ONE] = texture;
  //TWO
  reset_col(arr);
  for(std::size_t i = 2; i < 9; i++){
    arr[arr_loc(i,1)] = Block::Colour::BLACK;
    arr[arr_loc(i,2)] = Block::Colour::BLACK;
  }
  for(std::size_t i = 2; i < 10; i++){
    arr[arr_loc(i,9)] = Block::Colour::BLACK;
    arr[arr_loc(i,10)] = Block::Colour::BLACK;
  }
  for(std::size_t i = 3; i < 10; i++){
    arr[arr_loc(i,11-i)] = Block::Colour::BLACK;
    arr[arr_loc(i,12-i)] = Block::Colour::BLACK;
    arr[arr_loc(i,13-i)] = Block::Colour::BLACK;
  }
  //arr[arr_loc(1,10)] = Block::Colour::BLACK;
  arr[arr_loc(7,3)] = Block::Colour::BLACK;
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::TWO] = texture;
  //THREE
  reset_col(arr);
  for(std::size_t i = 0; i < 7; i++){
    arr[arr_loc(i+2,1)] = Block::Colour::BLACK;
    arr[arr_loc(i+2,2)] = Block::Colour::BLACK;
    arr[arr_loc(i+2,9)] = Block::Colour::BLACK;
    arr[arr_loc(i+2,10)] = Block::Colour::BLACK;
    arr[arr_loc(i+4,5)] = Block::Colour::BLACK;
    arr[arr_loc(i+4,6)] = Block::Colour::BLACK;
  }
  for(std::size_t i = 0; i < 3; i++){
    arr[arr_loc(9,i+2)] = Block::Colour::BLACK;
    arr[arr_loc(10,i+2)] = Block::Colour::BLACK;
    arr[arr_loc(9,i+7)] = Block::Colour::BLACK;
    arr[arr_loc(10,i+7)] = Block::Colour::BLACK;
  }
  for(std::size_t i = 0; i < 2; i++){
    arr[arr_loc(1,i+2)] = Block::Colour::BLACK;
    arr[arr_loc(1,i+8)] = Block::Colour::BLACK;
  }
  arr[arr_loc(9,1)] = Block::Colour::BLACK;
  arr[arr_loc(9,10)] = Block::Colour::BLACK;
  arr[arr_loc(2,3)] = Block::Colour::BLACK;
  arr[arr_loc(2,8)] = Block::Colour::BLACK;
  texture.loadFromImage(Block::to_image(arr));
  Sprite::textureMap[Block::Type::THREE] = texture;
  //FOUR
  //FIVE
  //SIX
  //SEVEN
  //EIGHT
  //NINE

}
