#include "Player.hpp"

void Player::state_update(Action act)
{
  switch(act){
  case Player::Action::MOVE_TOP:
    if(pos.y == 1){
      --pos.y;
    }
    else {
      pos.y = 15;
    }
    break;
  case Player::Action::MOVE_RGH:
    if(pos.x == 15){
      ++pos.x;
    }
    else {
      pos.x = 1;
    }
    break;
  case Player::Action::MOVE_BOT:
    if(pos.y == 15){
      ++pos.y;
    }
    else {
      pos.y = 1;
    }
    break;
  case Player::Action::MOVE_LFT:
    if(pos.x == 1){
      --pos.x;
    }
    else {
      pos.x = 15;
    }
    break;
    //default:
  case Player::Action::ATTACK_RNG:break;
  case Player::Action::ATTACK_MLE:break;
  }
}

void Player::game_display_draw(Block::Type * arr) const
{
  std::size_t const loc = pos.y * 16 + pos.x;
  switch(faceDir){
  case sys::Dir::TOP: arr[loc] = Block::Type::PLAYER_UP; break;
  case sys::Dir::RGH: arr[loc] = Block::Type::PLAYER_RIGHT; break;
  case sys::Dir::BOT: arr[loc] = Block::Type::PLAYER_DOWN; break;
  case sys::Dir::LFT: arr[loc] = Block::Type::PLAYER_LEFT; break;
  }
}

Player::Player():
  pos{7,7},
  faceDir{sys::Dir::RGH}
{
}

Player::~Player(){}
