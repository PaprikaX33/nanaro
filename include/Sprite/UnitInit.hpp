#ifndef NANARO_SPRITE_UNIT_INIT_HEAD_HPP
#define NANARO_SPRITE_UNIT_INIT_HEAD_HPP
#include "Block/PixCol.hpp"

namespace Sprite {
  namespace Init {
    void reset_col(Block::Colour *);
    void opaque(Block::Colour *);
    void wall(Block::Colour *);
    void exit(Block::Colour *);
    void enemy(Block::Colour *);
    void player(Block::Colour *);
    void weapon_melee(Block::Colour *);
    void weapon_range(Block::Colour *);
    void key(Block::Colour *);
    void alpha_a_i(Block::Colour *);
    void alpha_j_r(Block::Colour *);
    void alpha_s_z(Block::Colour *);
    void num(Block::Colour *);
    void punc(Block::Colour *);
  }
}

#endif //NANARO_SPRITE_UNIT_INIT_HEAD_HPP
