#include "Block/PixCol.hpp"
#include "Block/Type.hpp"
#include "Sprite/Draw.hpp"
#include "Sprite/Init.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstddef>

int main(int argc, char ** argv)
{
  (void)argc; (void)argv;
  Sprite::initialize();
  sf::RenderWindow window(sf::VideoMode(800,600), "Hello World!");
  sf::View viewScaler(sf::FloatRect(0, 0, 360, 264)); //Not an exact square, but good enough
  enum Block::Type walla[660u];
  for(std::size_t i = 0; i < 660u; i++){
    walla[i] = Block::Type::WALL_A;
  }
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
    Sprite::draw(window, walla);
    window.display();
  }
  return 0;
}
