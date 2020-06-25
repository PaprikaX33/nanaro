#include "Ui/Compose.hpp"
#include "Block/Type.hpp"
#include "Grid/Wall.hpp"
#include <cstddef>

static enum Block::Type renderBuff[660u];
static void write_separator(enum Block::Type * );

enum Block::Type * Ui::compose(enum Block::Type * item, enum Block::Type * status, enum Block::Type * game)
{

  write_separator();
  return renderBuff;
}


void write_separator()
{
  for(std::size_t i = 1; i < 21u; i++){
    renderBuff[0 + (30 * i)] = Block::Type::BLACK;
    renderBuff[29 + (30 * i)] = Block::Type::BLACK;
  }
  for(std::size_t i = 0; i < 30u; i++){
    renderBuff[i + (30 * 0)] = Block::Type::BLACK;
    renderBuff[i + (30 * 17)] = Block::Type::BLACK;
    renderBuff[i + (30 * 21)] = Block::Type::BLACK;
  }
  for(std::size_t i = 1; i < 16u; i++){
    renderBuff[12 + (30 * i)] = Block::Type::BLACK;
  }
}
