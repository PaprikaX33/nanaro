#include "Block/PixCol.hpp"
#include "Block/Type.hpp"
#include "Sprite/Draw.hpp"
#include "Sprite/Init.hpp"
#include "Grid/Wall.hpp"
#include "System/Random.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstddef>
#include <iostream>

void write_separator(enum Block::Type * );

int main(int argc, char ** argv)
{
  (void)argc; (void)argv;
  Sprite::initialize();
  sys::rng::init();
  sf::RenderWindow window(sf::VideoMode(800,600), "Hello World!");
  sf::View viewScaler(sf::FloatRect(0, 0, 360, 264)); //Not an exact square, but good enough
  enum Block::Type testingGrid[660u];
  for(std::size_t i = 0; i < 660u; i++){
    testingGrid[i] = Block::Type::EXIT_UNLOCKED;
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
  Grid::Border::draw(testingGrid, Grid::Border::Type::MC);
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
