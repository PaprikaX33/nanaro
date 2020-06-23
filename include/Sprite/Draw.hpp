#ifndef NANARO_SPRITE_DRAW_HEAD_HPP
#define NANARO_SPRITE_DRAW_HEAD_HPP
#include "Block/Type.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace Sprite {
  void draw(sf::RenderTarget &, enum Block::Type *); //Always 30 * 22 = 660
}

#endif //NANARO_SPRITE_DRAW_HEAD_HPP
