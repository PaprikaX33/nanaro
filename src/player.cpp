#include "Player.hpp"

void Player::state_update(Action act)
{
  switch(act){
  case Player::Action::MOVE_TOP:
    if(pos.y != 1){
      --pos.y;
    }
    else {
      if(pos.x == 7 || pos.x == 8){
        pos.y = 14;
      }
    }
    faceDir = sys::Dir::TOP;
    break;
  case Player::Action::MOVE_RGH:
    if(pos.x != 14){
      ++pos.x;
    }
    else {
      if(pos.y == 7 || pos.y == 8){
        pos.x = 1;
      }
    }
    faceDir = sys::Dir::RGH;
    break;
  case Player::Action::MOVE_BOT:
    if(pos.y != 14){
      ++pos.y;
    }
    else {
      if(pos.x == 7 || pos.x == 8){
        pos.y = 1;
      }
    }
    faceDir = sys::Dir::BOT;
    break;
  case Player::Action::MOVE_LFT:
    if(pos.x != 1){
      --pos.x;
    }
    else {
      if(pos.y == 7 || pos.y == 8){
        pos.x = 14;
      }
    }
    faceDir = sys::Dir::LFT;
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
