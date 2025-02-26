#pragma once

#include "circle_simulation/types.hpp"

class World {
   public:
    const int width_pixels;
    const int height_pixels;
    const real_t pixels_per_meter;
    const vec2 gravity;
    const real_t width;
    const real_t height;

    World(int width_pixels, int height_pixels, real_t pixels_per_meter, real_t gravity);

    vec2 to_pixels(const vec2& world_coords) const;
    real_t to_pixels(real_t value) const;

    real_t left() const;
    real_t right() const;
    real_t bottom() const;
    real_t top() const;

    void handle_wall_collisions(vec2& position, vec2& velocity, real_t radius) const;
};
