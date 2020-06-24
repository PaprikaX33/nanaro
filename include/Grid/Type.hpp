#ifndef NANARO_GRID_TYPE_HEAD_HPP
#define NANARO_GRID_TYPE_HEAD_HPP
#include <cstdint>

namespace Grid {
  namespace Border {
    enum class Type : std::uint_least8_t {
                                          TOP_LFT,
                                          TOP_CNT,
                                          TOP_RGH,
                                          MID_LFT,
                                          MID_CNT,
                                          MID_RGH,
                                          BOT_LFT,
                                          BOT_CNT,
                                          BOT_RGH,

                                          TL = TOP_LFT, TC = TOP_CNT, TR = TOP_RGH,
                                          ML = MID_LFT, MC = MID_CNT, MR = MID_RGH,
                                          BL = BOT_LFT, BC = BOT_CNT, BR = BOT_RGH

    };
  }
}

#endif //NANARO_GRID_TYPE_HEAD_HPP
