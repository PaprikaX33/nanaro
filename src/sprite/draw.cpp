#include "Sprite/Draw.hpp"
#include "Sprite/Properties.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <cstddef>

void Sprite::draw(sf::RenderTarget & target, enum Block::Type * arr)
{
  sf::Sprite sprite;
  for(std::size_t y = 0; y < 22u; y++){
    for(std::size_t x = 0; x < 30u; x++){
      sprite.setPosition(static_cast<float>(x) * 12.0f,
                         static_cast<float>(y) * 12.0f);
      sprite.setTexture(Sprite::textureMap[arr[x + (y * 30u)]]);
      target.draw(sprite);
    }
  }

}
