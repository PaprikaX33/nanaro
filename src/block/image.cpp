#include "Block/Colour.hpp"
#include "Block/Image.hpp"
#include <SFML/Graphics/Image.hpp>
#include <cstddef>

sf::Image to_image(enum Block::Colour const * arr)
{
  sf::Uint8 imgArr[12u * 12u * 4u];
  sf::Image img;
  for(std::size_t i = 0; i < 12u * 12u; i++){
    sf::Color const col = Block::to_colour(arr[i]);
    std::size_t const m = i * 4u;
    imgArr[m + 0u] = col.r;
    imgArr[m + 1u] = col.g;
    imgArr[m + 2u] = col.b;
    imgArr[m + 3u] = col.a;
  }
  img.create(12u, 12u, imgArr);
  return img;
}
