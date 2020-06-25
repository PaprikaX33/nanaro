#ifndef NANARO_UI_COMPOSE_HEAD_HPP
#define NANARO_UI_COMPOSE_HEAD_HPP
#include "Block/Type.hpp"

namespace Ui {
  //Text: 11x16 = 176
  //Stat: 28x03 = 084
  //Game: 16x16 = 256
  enum Block::Type * compose(enum Block::Type * text, enum Block::Type * stat, enum Block::Type * game);
  //Returned array should be passed directly to Sprite::draw
}

#endif //NANARO_UI_COMPOSE_HEAD_HPP
