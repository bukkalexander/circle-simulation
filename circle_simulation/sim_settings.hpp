#pragma once

#include "circle_simulation/types.hpp"
struct SimSettings {
    const real_t fps;
    const real_t ups;

    SimSettings(real_t fps, real_t ups) : fps(fps), ups(ups) {}
};