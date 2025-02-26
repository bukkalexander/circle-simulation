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
    int spawn_limit = 100;           // number of circles to spawn
    int spawn_interval = 100;        // number of updates between spawns
    real_t gravity = 9.8;            // m/s^2
    int fps = 60;                    // frames per second
    int ups = 1000;                  // updates per second
};
// NOLINTEND(readability-magic-numbers)