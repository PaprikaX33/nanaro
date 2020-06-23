#ifndef NANARO_BLOCK_IMAGE_HEAD_HPP
#define NANARO_BLOCK_IMAGE_HEAD_HPP
#include "Block/Colour.hpp"
#include <SFML/Graphics/Image.hpp>

namespace Block {
  sf::Image to_image(enum Block::Colour const *); //Exactly 12 * 12 = 224
}

#endif //NANARO_BLOCK_IMAGE_HEAD_HPP
