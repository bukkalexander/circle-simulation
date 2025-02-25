#pragma once
#include <glm/vec2.hpp>

#include "circle_simulation/consts.hpp"
namespace utils {

glm::vec2 world_to_pixel_vec2(glm::vec2 vec) {
    return {vec.x * consts::METERS_TO_PIXELS,
            consts::WINDOW_HEIGHT - (vec.y * consts::METERS_TO_PIXELS)};
}

float world_to_pixel_radius(float radius) { return radius * consts::METERS_TO_PIXELS; }
}  // namespace utils