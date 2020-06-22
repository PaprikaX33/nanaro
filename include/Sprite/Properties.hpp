#ifndef NANARO_SPRITE_PROPERTIES_HEAD_HPP
#define NANARO_SPRITE_PROPERTIES_HEAD_HPP
#include "Block/Type.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <unordered_map>
#include <cstddef>

namespace Sprite {
  static constexpr std::size_t arrSize = 12u * 12u;
  extern std::unordered_map<enum Block::Type, sf::Texture> textureMap;

  std::size_t constexpr arr_loc(std::size_t x, std::size_t y)
  {
    return x + (y * 12);
  }
}

#endif //NANARO_SPRITE_PROPERTIES_HEAD_HPP
