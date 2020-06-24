#include "Block/PixCol.hpp"
#include "Block/Type.hpp"
#include "Sprite/Draw.hpp"
#include "Sprite/Init.hpp"
#include "System/Random.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstddef>
#include <iostream>

void write_separator(enum Block::Type * );
void draw_border(enum Block::Type * );

int main(int argc, char ** argv)
{
  (void)argc; (void)argv;
  Sprite::initialize();
  sys::rng::init();
  sf::RenderWindow window(sf::VideoMode(800,600), "Hello World!");
  sf::View viewScaler(sf::FloatRect(0, 0, 360, 264)); //Not an exact square, but good enough
  enum Block::Type testingGrid[660u];
  for(std::size_t i = 0; i < 660u; i++){
    testingGrid[i] = Block::Type::WHITE;
  }
  testingGrid[30+1] = Block::Type::ZERO;
  testingGrid[30+2] = Block::Type::ONE;
  testingGrid[30+3] = Block::Type::TWO;
  testingGrid[30+4] = Block::Type::THREE;
  testingGrid[30+5] = Block::Type::FOUR;
  testingGrid[30+6] = Block::Type::FIVE;
  testingGrid[30+7] = Block::Type::SIX;
  testingGrid[30+8] = Block::Type::SEVEN;
  testingGrid[30+9] = Block::Type::NINE;
  write_separator(testingGrid);
  draw_border(testingGrid);
  window.setView(viewScaler);
  window.setFramerateLimit(60);
  while(window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event)){
      if(event.type == sf::Event::Closed ||
         (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Button::Right) ||
         (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Key::Q && event.key.control)){
        window.close();
      }
    }
    window.clear();
    Sprite::draw(window, testingGrid);
    window.display();
  }
  return 0;
}

void write_separator(enum Block::Type * arr)
{
  //arr[x + (30 * y)] = BlocK::Type::BLACK;
  for(std::size_t i = 0; i < 22u; i++){
    arr[0 + (30 * i)] = Block::Type::BLACK;
    arr[12 + (30 * i)] = Block::Type::BLACK;
    arr[29 + (30 * i)] = Block::Type::BLACK;
  }
  for(std::size_t i = 0; i < 30u; i++){
    arr[i + (30 * 0)] = Block::Type::BLACK;
    arr[i + (30 * 17)] = Block::Type::BLACK;
    arr[i + (30 * 21)] = Block::Type::BLACK;
  }
}

void draw_border(enum Block::Type * arr)
{
  for(std::size_t i = 0; i < 16u; i++){
    switch(sys::rng::wall()){
    default:
    case 0: arr[30+13+i] = Block::Type::WALL_A; break;
    case 1: arr[30+13+i] = Block::Type::WALL_B; break;
    case 2: arr[30+13+i] = Block::Type::WALL_C; break;
    case 3: arr[30+13+i] = Block::Type::WALL_D; break;
    }
    switch(sys::rng::wall()){
    default:
    case 0: arr[480+13+i] = Block::Type::WALL_A; break;
    case 1: arr[480+13+i] = Block::Type::WALL_B; break;
    case 2: arr[480+13+i] = Block::Type::WALL_C; break;
    case 3: arr[480+13+i] = Block::Type::WALL_D; break;
    }
  }
  for(std::size_t i = 2; i < 16u; i++){
    switch(sys::rng::wall()){
    default:
    case 0: arr[30*i+13] = Block::Type::WALL_A; break;
    case 1: arr[30*i+13] = Block::Type::WALL_B; break;
    case 2: arr[30*i+13] = Block::Type::WALL_C; break;
    case 3: arr[30*i+13] = Block::Type::WALL_D; break;
    }
    switch(sys::rng::wall()){
    default:
    case 0: arr[30*i+28] = Block::Type::WALL_A; break;
    case 1: arr[30*i+28] = Block::Type::WALL_B; break;
    case 2: arr[30*i+28] = Block::Type::WALL_C; break;
    case 3: arr[30*i+28] = Block::Type::WALL_D; break;
    }
  }
  return;
}
