#include "Block/PixCol.hpp"
#include "Player.hpp"
#include "Block/Type.hpp"
#include "Sprite/Draw.hpp"
#include "Sprite/Init.hpp"
#include "Grid/Wall.hpp"
#include "System/Random.hpp"
#include "Ui/Compose.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstddef>
#include <iostream>

int main(int argc, char ** argv)
{
  (void)argc; (void)argv;
  Sprite::initialize();
  sys::rng::init();
  sf::RenderWindow window(sf::VideoMode(800,600), "NAna RO!");
  sf::View viewScaler(sf::FloatRect(0, 0, 360, 264)); //Not an exact square, but good enough
  enum Block::Type game[256u];
  enum Block::Type stat[84u];
  enum Block::Type text[176u]; //for testing
  for(std::size_t i = 0; i < 176u; i++){
    switch(i % 10u){
    case 0: text[i] = Block::Type::ZERO; break;
    case 1: text[i] = Block::Type::ONE; break;
    case 2: text[i] = Block::Type::TWO; break;
    case 3: text[i] = Block::Type::THREE; break;
    case 4: text[i] = Block::Type::FOUR; break;
    case 5: text[i] = Block::Type::FIVE; break;
    case 6: text[i] = Block::Type::SIX; break;
    case 7: text[i] = Block::Type::SEVEN; break;
    case 8: text[i] = Block::Type::EIGHT; break;
    case 9: text[i] = Block::Type::NINE; break;
    }
  }
  for(std::size_t i = 0; i < 84u; i++){
    switch(i % 10u){
    case 0: stat[i] = Block::Type::ZERO; break;
    case 1: stat[i] = Block::Type::ONE; break;
    case 2: stat[i] = Block::Type::TWO; break;
    case 3: stat[i] = Block::Type::THREE; break;
    case 4: stat[i] = Block::Type::FOUR; break;
    case 5: stat[i] = Block::Type::FIVE; break;
    case 6: stat[i] = Block::Type::SIX; break;
    case 7: stat[i] = Block::Type::SEVEN; break;
    case 8: stat[i] = Block::Type::EIGHT; break;
    case 9: stat[i] = Block::Type::NINE; break;
    }
  }
  for(std::size_t i = 0; i < 256u; i++){
    switch(i % 5u){
    case 0: game[i] = Block::Type::ENEMY_UP; break;
    case 1: game[i] = Block::Type::ENEMY_RIGHT; break;
    case 2: game[i] = Block::Type::ENEMY_DOWN; break;
    case 3: game[i] = Block::Type::ENEMY_LEFT; break;
    case 4: game[i] = Block::Type::ENEMY_HIT; break;
    }
  }
  Grid::Border::draw(game, Grid::Border::Type::MC);
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
    Sprite::draw(window, Ui::compose(text, stat, game)); //testing only
    window.display();
  }
  return 0;
}
