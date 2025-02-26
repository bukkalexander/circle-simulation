#pragma once

#include "circle_simulation/cli_args.hpp"
#include "circle_simulation/types.hpp"
struct Config {
    // Base user values
    const int window_width;
    const int window_height;
    const real_t min_circle_radius;
    const real_t max_circle_radius;
    const int spawn_limit;
    const int spawn_interval;
    const real_t gravity;
    const int fps;
    const int ups;
    const real_t pixels_per_meter = 100.0;

    // Derived values
    const real_t window_left = 0;
    const real_t window_right;
    const real_t window_top = 0;
    const real_t window_bottom;
    const real_t meters_to_pixels;
    const real_t pixels_to_meters;

    Config(const CliArgs &args)
        : window_width(args.window_width),
          window_height(args.window_height),
          min_circle_radius(args.min_circle_radius),
          max_circle_radius(args.max_circle_radius),
          spawn_limit(args.spawn_limit),
          spawn_interval(args.spawn_interval),
          gravity(args.gravity),
          fps(args.fps),
          ups(args.ups),
          // Derived values
          window_right(args.window_width),
          window_bottom(args.window_height),
          meters_to_pixels(pixels_per_meter),
          pixels_to_meters(1.0F / pixels_per_meter) {}
};