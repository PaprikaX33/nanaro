#include "System/Random.hpp"
#include <cstddef>
#include <random>
#include <ctime>

static std::default_random_engine engine;
static std::uniform_int_distribution<std::size_t> wall;

void sys::rng::init(void)
{
  std::random_device dev;
  std::seed_seq seed{dev(), dev(), dev(), static_cast<unsigned int>(std::time(nullptr))};
  engine = std::default_random_engine{seed};
  ::wall = std::uniform_int_distribution<std::size_t>{0,3};
}

std::size_t sys::rng::wall(void) // 0 <= x < 4
{
  return ::wall(engine);
}


std::size_t sys::rng::general_set(std::size_t max, std::size_t min)
{
  std::uniform_int_distribution<std::size_t> distrb{min, max - 1};
  return distrb(engine);
}
