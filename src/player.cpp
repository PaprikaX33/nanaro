#include "Player.hpp"

void Player::state_update(Action act)
{
  switch(act){
  case Player::Action::MOVE_TOP:
    if(_pos.y != 1){
      --_pos.y;
    }
    else {
      if(_pos.x == 7 || _pos.x == 8){
        _pos.y = 14;
      }
    }
    _faceDir = sys::Dir::TOP;
    break;
  case Player::Action::MOVE_RGH:
    if(_pos.x != 14){
      ++_pos.x;
    }
    else {
      if(_pos.y == 7 || _pos.y == 8){
        _pos.x = 1;
      }
    }
    _faceDir = sys::Dir::RGH;
    break;
  case Player::Action::MOVE_BOT:
    if(_pos.y != 14){
      ++_pos.y;
    }
    else {
      if(_pos.x == 7 || _pos.x == 8){
        _pos.y = 1;
      }
    }
    _faceDir = sys::Dir::BOT;
    break;
  case Player::Action::MOVE_LFT:
    if(_pos.x != 1){
      --_pos.x;
    }
    else {
      if(_pos.y == 7 || _pos.y == 8){
        _pos.x = 14;
      }
    }
    _faceDir = sys::Dir::LFT;
    break;
    //default:
  case Player::Action::ATTACK_RNG:break;
  case Player::Action::ATTACK_MLE:break;
  }
}

void Player::game_display_draw(Block::Type * arr) const
{
  std::size_t const loc = _pos.y * 16 + _pos.x;
  switch(_faceDir){
  case sys::Dir::TOP: arr[loc] = Block::Type::PLAYER_UP; break;
  case sys::Dir::RGH: arr[loc] = Block::Type::PLAYER_RIGHT; break;
  case sys::Dir::BOT: arr[loc] = Block::Type::PLAYER_DOWN; break;
  case sys::Dir::LFT: arr[loc] = Block::Type::PLAYER_LEFT; break;
  }
}

Player::Player():
  _pos{7,7},
  _faceDir{sys::Dir::RGH}
{
}

Player::~Player(){}
