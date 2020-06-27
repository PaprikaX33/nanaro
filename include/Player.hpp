#ifndef NANARO_PLAYER_PROPERTIES_HEAD_HPP
#define NANARO_PLAYER_PROPERTIES_HEAD_HPP
#include "System/Pair.hpp"
#include "System/Direction.hpp"
#include "Block/Type.hpp"

struct Player{
  enum class Action {
                     MOVE_TOP,
                     MOVE_RGH,
                     MOVE_BOT,
                     MOVE_LFT,
                     ATTACK_RNG,
                     ATTACK_MLE
  };
  sys::Pairu pos; //1-14 (Should not replace wall)
  enum sys::Dir faceDir;
  void state_update(Action);
  void game_display_draw(Block::Type *) const; //Block array of the game field
  //void hit(void);
  Player();
  ~Player();
};


#endif //NANARO_PLAYER_PROPERTIES_HEAD_HPP
