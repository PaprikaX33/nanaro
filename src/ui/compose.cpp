#include "Ui/Compose.hpp"
#include "Block/Type.hpp"
#include "Grid/Wall.hpp"
#include <cstddef>

static enum Block::Type renderBuff[660u];
static void write_separator();

enum Block::Type * Ui::compose(enum Block::Type * text, enum Block::Type * stat, enum Block::Type * game)
{
  //FOR TESTING
  if(text){
    for(std::size_t i = 0; i < 16; i++) {
      for(std::size_t o = 0; o < 11; o++) {
        renderBuff[(i+1)*30u+(o + 1)] = text[i*11+o];
      }
    }
  }
  else {
    for(std::size_t i = 0; i < 16; i++) {
      for(std::size_t o = 0; o < 11; o++) {
        renderBuff[(i+1)*30u+(o + 1)] = Block::Type::BLANK;
      }
    }
  }
  if(stat){
    for(std::size_t i = 0; i < 3; i++) {
      for(std::size_t o = 0; o < 28; o++) {
        renderBuff[(i+18)*30u+(o + 1)] = stat[i*28+o];
      }
    }
  }
  else {
    for(std::size_t i = 0; i < 3; i++) {
      for(std::size_t o = 0; o < 28; o++) {
        renderBuff[(i+18)*30u+(o + 1)] = Block::Type::BLANK;
      }
    }
  }
  if(game){
    for(std::size_t i = 0; i < 16; i++) {
      for(std::size_t o = 0; o < 16; o++) {
        renderBuff[(i+1)*30u+(o+13)] = game[i*16+o];
      }
    }
  }
  else {
    for(std::size_t i = 0; i < 16; i++) {
      for(std::size_t o = 0; o < 16; o++) {
        renderBuff[(i+1)*30u+(o+13)] = Block::Type::BLANK;
      }
    }
  }
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
  for(std::size_t i = 1; i < 17u; i++){
    renderBuff[12 + (30 * i)] = Block::Type::BLACK;
  }
}
