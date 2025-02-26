#pragma once

#include "circle_simulation/types.hpp"

struct CircleSettings {
    const int spawn_limit;
    const int spawn_interval;
    const int spawn_max_retries;
    const real_t min_circle_radius;
    const real_t max_circle_radius;

    CircleSettings(int spawn_limit, int spawn_interval, int spawn_max_retries,
                   real_t min_circle_radius, real_t max_circle_radius)
        : spawn_limit(spawn_limit),
          spawn_interval(spawn_interval),
          spawn_max_retries(spawn_max_retries),
          min_circle_radius(min_circle_radius),
          max_circle_radius(max_circle_radius) {}
};
