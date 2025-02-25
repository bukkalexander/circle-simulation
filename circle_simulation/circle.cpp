#include "circle_simulation/circle.hpp"

#include <glm/glm.hpp>

#include "circle_simulation/utils.hpp"

// NOLINTBEGIN (bugprone-easily-swappable-parameters)
Circle::Circle(glm::vec2 position_, glm::vec2 velocity_, float radius_)
    : position(position_), velocity(velocity_), radius(radius_) {}
// NOLINTEND (bugprone-easily-swappable-parameters)
void Circle::update(float time_step) {
    const glm::vec2 gravity(0.0F, -9.8F);
    velocity += gravity * time_step;
    position += velocity * time_step;

    // Define world boundaries in meters
    float world_left = consts::WINDOW_LEFT * consts::PIXELS_TO_METERS;
    float world_right = consts::WINDOW_WIDTH * consts::PIXELS_TO_METERS;
    float world_bottom = 0.0F;
    float world_top = consts::WINDOW_HEIGHT * consts::PIXELS_TO_METERS;

    // Check left/right collisions:
    if (position.x - radius < world_left) {
        position.x = world_left + radius;  // reposition inside the left boundary
        velocity.x = -velocity.x;          // reflect horizontal velocity
    } else if (position.x + radius > world_right) {
        position.x = world_right - radius;  // reposition inside the right boundary
        velocity.x = -velocity.x;
    }

    // Check bottom/top collisions:
    if (position.y - radius < world_bottom) {
        position.y = world_bottom + radius;  // reposition above the bottom boundary
        velocity.y = -velocity.y;
    } else if (position.y + radius > world_top) {
        position.y = world_top - radius;  // reposition below the top boundary
        velocity.y = -velocity.y;
    }
}

void Circle::render(const Renderer& renderer) const {
    renderer.draw_circle(utils::world_to_pixel_vec2(position),
                         utils::world_to_pixel_radius(radius));
}
