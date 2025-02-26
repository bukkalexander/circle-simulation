#pragma once

#include "circle_simulation/types.hpp"

// NOLINTBEGIN(readability-magic-numbers)
struct CliArgs {
    // Window configuration (in pixels)
    int window_width = 640;
    int window_height = 480;

    // Circle simulation parameters.
    real_t min_circle_radius = 0.1;  // meters
    real_t max_circle_radius = 0.3;  // meters
    int spawn_limit = 10;            // number of circles to spawn
    real_t spawn_interval = 60.0;    // number of updates between spawns
    real_t gravity = 9.8;            // m/s^2
    real_t fps = 60.0;               // frames per second
    real_t ups = 60.0;               // updates per second
};
// NOLINTEND(readability-magic-numbers)