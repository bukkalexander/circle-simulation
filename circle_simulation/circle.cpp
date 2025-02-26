#include "circle_simulation/circle.hpp"

#include <glm/gtx/norm.hpp>

#include "circle_simulation/types.hpp"
#include "circle_simulation/world.hpp"

Circle::Circle(vec2 position, vec2 velocity, real_t radius, const World& world)
    : position_(position), velocity_(velocity), radius_(radius), world_(world) {}

void Circle::update(real_t time_step) {
    velocity_ += world_.gravity * time_step;
    position_ += velocity_ * time_step;

    world_.handle_wall_collisions(position_, velocity_, radius_);
}

void Circle::render(const Renderer& renderer) const {
    renderer.draw_circle(world_.to_pixels(position_), world_.to_pixels(radius_));
}

bool Circle::collides(const Circle& other) const {
    real_t distance_sq = glm::length2(position_ - other.position_);
    real_t combined_radius = radius_ + other.radius_;
    return distance_sq < combined_radius * combined_radius;
}