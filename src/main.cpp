#include "Block/ToBlock.hpp"
#include "Block/PixCol.hpp"
#include "Block/Type.hpp"
#include "Grid/Generate.hpp"
#include "Grid/Selection.hpp"
#include "Grid/Layout.hpp"
#include "Grid/Wall.hpp"
#include "Player.hpp"
#include "Sprite/Draw.hpp"
#include "Sprite/Init.hpp"
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
  //auto const layout = Grid::generate_layout(12);
  Grid::generate_grid(5);
  Player play;
  sf::RenderWindow window(sf::VideoMode(800,600), "NAna RO!");
  // for(auto const i : layout){
  //   std::cout << i.first << '\t' << i.second << '\n';
  // }
  sf::View viewScaler(sf::FloatRect(0, 0, 360, 264)); //Not an exact square, but good enough
  enum Block::Type game[256u];
  //enum Block::Type gamePlain[256u];
  enum Block::Type stat[84u];
  enum Block::Type text[176u]; //for testing
  for(std::size_t i = 0; i < 176u; i++){
    text[i] = Block::conv::num(i%10);
  }
  for(std::size_t i = 0; i < 84u; i++){
    stat[i] = Block::conv::num(i%10);
    switch(i % 10u){
    }
  }
  // for(std::size_t i = 0; i < 256u; i++){
  //   gamePlain[i] = Block::Type::BLANK;
  // }
  //Grid::Border::draw(gamePlain, 0b1101);
  window.setView(viewScaler);
  window.setFramerateLimit(60);
  while(window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event)){
      if(event.type == sf::Event::Closed ||
         (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Button::Right)){// ||
        //(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Key::Q && event.key.control)){
        window.close();
        break;
      }
      switch(event.type){
      case sf::Event::KeyReleased:
        switch(event.key.code){
        case sf::Keyboard::Key::Q:
          if(event.key.control){
            window.close();
          }
          break;
        case sf::Keyboard::Key::W: play.state_update(Player::Action::MOVE_TOP); break;
        case sf::Keyboard::Key::A: play.state_update(Player::Action::MOVE_LFT); break;
        case sf::Keyboard::Key::S: play.state_update(Player::Action::MOVE_BOT); break;
        case sf::Keyboard::Key::D: play.state_update(Player::Action::MOVE_RGH); break;
        default:
          break;
        }
        break;
      default:
        break;
      }
    }
    //auto plainField = Grid::get(std::pair<int,int>(0,0));
    auto plainField = Grid::get();
    if(plainField) {
      for(std::size_t i = 0; i < 256u; i++){
        game[i] = plainField[i];
      }
      play.game_display_draw(game);
    }
    window.clear();
    Sprite::draw(window, Ui::compose(text, stat, game));
    //Sprite::draw(window, Ui::compose(nullptr, nullptr, nullptr)); //testing only
    window.display();
  }
  (void)game;
  (void)stat;
  (void)text;
  return 0;
}
