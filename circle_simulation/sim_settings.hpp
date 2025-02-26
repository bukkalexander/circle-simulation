#pragma once

#include "circle_simulation/types.hpp"
struct SimSettings {
    const int spawn_limit;
    const real_t spawn_interval;
    const real_t fps;
    const real_t ups;

    // Derived values
    const real_t time_step;

    SimSettings(int spawn_limit, real_t spawn_interval, real_t fps, real_t ups)
        : spawn_limit(spawn_limit),
          spawn_interval(spawn_interval),
          fps(fps),
          ups(ups),
          // Derived values
          time_step(1.0 / ups) {}
};