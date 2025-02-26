#pragma once

#include "circle_simulation/types.hpp"

struct CircleSettings {
    const int spawn_limit;
    const int spawn_interval;
    const real_t min_circle_radius;
    const real_t max_circle_radius;

    CircleSettings(int spawn_limit, int spawn_interval, real_t min_circle_radius,
                   real_t max_circle_radius)
        : spawn_limit(spawn_limit),
          spawn_interval(spawn_interval),
          min_circle_radius(min_circle_radius),
          max_circle_radius(max_circle_radius) {}
};
