#include "Player.hpp"
#include "Grid/Selection.hpp"

static bool is_movable(sys::Pairu);

void Player::state_update(Action act)
{
  switch(act){
  case Player::Action::MOVE_TOP:
    if(_pos.y == 0){
      Grid::screenPos = std::pair<int,int>(Grid::screenPos.first, Grid::screenPos.second - 1);
      _pos.y = 15;
      return;
    }
    if(is_movable({_pos.x, _pos.y - 1})){
      --_pos.y;
    }
    _faceDir = sys::Dir::TOP;
    return;
  case Player::Action::MOVE_RGH:
    if(_pos.x == 15){
      Grid::screenPos = std::pair<int,int>(Grid::screenPos.first + 1, Grid::screenPos.second);
      _pos.x = 0;
      return;
    }
    if(is_movable({_pos.x + 1, _pos.y})){
      ++_pos.x;
    }
    _faceDir = sys::Dir::RGH;
    return;
  case Player::Action::MOVE_BOT:
    if(_pos.y == 15){
      Grid::screenPos = std::pair<int,int>(Grid::screenPos.first, Grid::screenPos.second + 1);
      _pos.y = 0;
      return;
    }
    if(is_movable({_pos.x, _pos.y + 1})){
      ++_pos.y;
    }
    _faceDir = sys::Dir::BOT;
    return;
  case Player::Action::MOVE_LFT:
    if(_pos.x == 0){
      Grid::screenPos = std::pair<int,int>(Grid::screenPos.first - 1, Grid::screenPos.second);
      _pos.x = 15;
      return;
    }
    if(is_movable({_pos.x - 1, _pos.y})){
      --_pos.x;
    }
    _faceDir = sys::Dir::LFT;
    return;
    //default:
  case Player::Action::ATTACK_RNG:return;
  case Player::Action::ATTACK_MLE:return;
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

bool is_movable(sys::Pairu pos)
{
  auto const field = Grid::get();
  auto const block = field[pos.y * 16u + pos.x];
  switch(block){
  case Block::Type::WALL_A:
  case Block::Type::WALL_B:
  case Block::Type::WALL_C:
  case Block::Type::WALL_D:
    return false;
  default:
    return true;
  }
}
