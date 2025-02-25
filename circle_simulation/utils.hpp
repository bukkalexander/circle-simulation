#pragma once

#include "circle_simulation/types.hpp"
namespace utils {

vec2 world_to_pixel_vec2(vec2 vec, real_t meters_to_pixels, real_t world_height) {
    return {vec.x * meters_to_pixels, (world_height - vec.y) * meters_to_pixels};
}

real_t world_to_pixel_radius(real_t radius, real_t meters_to_pixels) {
    return radius * meters_to_pixels;
}
}  // namespace utils