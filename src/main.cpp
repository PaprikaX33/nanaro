#include "Block/PixCol.hpp"
#include "Block/Type.hpp"
#include "Sprite/Draw.hpp"
#include "Sprite/Init.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstddef>

void write_separator(enum Block::Type * );

int main(int argc, char ** argv)
{
  (void)argc; (void)argv;
  Sprite::initialize();
  sf::RenderWindow window(sf::VideoMode(800,600), "Hello World!");
  sf::View viewScaler(sf::FloatRect(0, 0, 360, 264)); //Not an exact square, but good enough
  enum Block::Type testingGrid[660u];
  for(std::size_t i = 0; i < 660u; i++){
    // switch(i % 2){
    // case 0: testingGrid[i] = Block::Type::ONE; break;
    // case 1: testingGrid[i] = Block::Type::EXIT_LOCKED; break;
    // }
    testingGrid[i] = Block::Type::NINE;

    //testingGrid[i] = Block::Type::WALL_C;
  }
  write_separator(testingGrid);
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
