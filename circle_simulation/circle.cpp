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
}

void Circle::render(const Renderer& renderer) const {
    renderer.draw_circle(utils::world_to_pixel_vec2(position),
                         utils::world_to_pixel_radius(radius));
}
