#pragma once

#include "circle_simulation/types.hpp"
#include "circle_simulation/user_config.hpp"
struct GlobalConfig {
    // Base user values.
    const int window_width;
    const int window_height;
    const real_t min_circle_radius;
    const real_t max_circle_radius;
    const int spawn_limit;
    const real_t spawn_interval;
    const real_t gravity;
    const real_t fps;
    const real_t ups;
    const real_t pixels_per_meter = 100.0;

    // Derived values.
    const real_t window_left = 0;
    const real_t window_right;
    const real_t window_top = 0;
    const real_t window_bottom;
    const real_t meters_to_pixels;
    const real_t pixels_to_meters;

    GlobalConfig(const UserConfig &user)
        : window_width(user.window_width),
          window_height(user.window_height),
          min_circle_radius(user.min_circle_radius),
          max_circle_radius(user.max_circle_radius),
          spawn_limit(user.spawn_limit),
          spawn_interval(user.spawn_interval),
          gravity(user.gravity),
          fps(user.fps),
          ups(user.ups),
          // Derived values
          window_right(user.window_width),
          window_bottom(user.window_height),
          meters_to_pixels(pixels_per_meter),
          pixels_to_meters(1.0F / pixels_per_meter) {}
};