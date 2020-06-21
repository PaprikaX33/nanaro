#include "Block/BlockColour.hpp"
#include <SFML/Graphics.hpp>

int main(int argc, char ** argv)
{
  (void)argc; (void)argv;
  sf::RenderWindow window(sf::VideoMode(800,600), "Hello World!");
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
    window.display();
  }
  return 0;
}
