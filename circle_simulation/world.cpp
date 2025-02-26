#include "circle_simulation/world.hpp"

World::World(int width_pixels, int height_pixels, real_t pixels_per_meter, real_t gravity)
    : width_pixels(width_pixels),
      height_pixels(height_pixels),
      pixels_per_meter(pixels_per_meter),
      gravity(0.0, -gravity),
      width(width_pixels / pixels_per_meter),
      height(height_pixels / pixels_per_meter) {}

vec2 World::to_pixels(const vec2& world_coords) const {
    return {world_coords.x * pixels_per_meter, (height - world_coords.y) * pixels_per_meter};
}

real_t World::to_pixels(real_t value) const { return value * pixels_per_meter; }

real_t World::left() const { return 0.0; }
real_t World::right() const { return width; }
real_t World::bottom() const { return 0.0; }
real_t World::top() const { return height; }

void World::handle_wall_collisions(vec2& position, vec2& velocity, real_t radius) const {
    // Check left/right collisions.
    if (position.x - radius < left()) {
        position.x = left() + radius;
        velocity.x = -velocity.x;
    } else if (position.x + radius > right()) {
        position.x = right() - radius;
        velocity.x = -velocity.x;
    }

    // Check bottom/top collisions.
    if (position.y - radius < bottom()) {
        position.y = bottom() + radius;
        velocity.y = -velocity.y;
    } else if (position.y + radius > top()) {
        position.y = top() - radius;
        velocity.y = -velocity.y;
    }
}
