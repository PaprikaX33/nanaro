#include "System/Random.hpp"
#include <cstddef>
#include <random>

static std::default_random_engine engine;
static std::uniform_int_distribution<std::size_t> wall;

void sys::rng::init(void)
{
  std::random_device dev;
  engine = std::default_random_engine{dev()};
  ::wall = std::uniform_int_distribution<std::size_t>{0,4};
}

std::size_t sys::rng::wall(void) // 0 <= x < 4
{
  return ::wall(engine);
}
