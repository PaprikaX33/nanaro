#ifndef NANARO_BLOCK_TYPE_HEAD_HPP
#define NANARO_BLOCK_TYPE_HEAD_HPP
#include <cstdint>

namespace Block{
  enum class Type : std::uint8_t {//OPAQUE BLOCK
                                  OPAQUE_WHITE,
                                  OPAQUE_BLACK,
                                  OPAQUE_RED,
                                  OPAQUE_GREEN,

                                  //WALLS
                                  WALL_A,
                                  WALL_B,
                                  WALL_C,
                                  WALL_D,

                                  //EXIT POINT
                                  EXIT_LOCKED,
                                  EXIT_UNLOCKED,

                                  //ENEMY
                                  ENEMY_UP,
                                  ENEMY_LEFT,
                                  ENEMY_DOWN,
                                  ENEMY_RIGHT,
                                  ENEMY_HIT,

                                  //PLAYER
                                  PLAYER_UP,
                                  PLAYER_LEFT,
                                  PLAYER_DOWN,
                                  PLAYER_RIGHT,
                                  PLAYER_HIT,

                                  //WEAPON
                                  WEAPON_MELEE,
                                  WEAPON_RANGE,

                                  //KEYS
                                  //MONO KEYS
                                  KEY_BLACK,
                                  KEY_RED,
                                  KEY_GREEN,

                                  //POLY KEYS
                                  KEY_BLACK_RED,
                                  KEY_BLACK_GREEN,
                                  KEY_RED_GREEN,
                                  KEY_GREEN_RED,

                                  //ALPHABETHS
                                  A,B,C,D,E,
                                  F,G,H,I,J,
                                  K,L,M,N,O,
                                  P,Q,R,S,T,
                                  U,V,W,X,Y,Z,

                                  //NUMBERS
                                  ZERO,
                                  ONE,
                                  TWO,
                                  THREE,
                                  FOUR,
                                  FIVE,
                                  SIX,
                                  SEVEN,
                                  EIGHT,
                                  NINE,

                                  //PUNCTUAL
                                  COLON,
                                  SEMI_COLON,
                                  DOT,
                                  COMMA,
                                  DASH,
                                  SPACE,

                                  //QOL
                                  WHITE = OPAQUE_WHITE,
                                  BLACK = OPAQUE_BLACK,
                                  RED = OPAQUE_RED,
                                  GREEN = OPAQUE_GREEN,
                                  BLANK = OPAQUE_WHITE
  };
}

#endif //NANARO_BLOCK_TYPE_HEAD_HPP
