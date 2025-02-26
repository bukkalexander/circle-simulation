#include "circle_simulation/circle.hpp"

#include <glm/gtx/norm.hpp>

#include "circle_simulation/types.hpp"
#include "circle_simulation/world.hpp"

Circle::Circle(vec2 position, vec2 velocity, real_t radius, const World& world)
    : position_(position),
      velocity_(velocity),
      radius_(radius),
      mass_(radius * radius),
      world_(world) {}

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

void Circle::resolve_collision(Circle& other) {  // NOLINTBEGIN(readability-identifier-length)
    if (!collides(other)) {
        return;
    }

    vec2 delta = position_ - other.position();
    real_t dist_sq = glm::dot(delta, delta);
    if (dist_sq == 0.0) {
        return;  // prevent division by zero.
    }
    real_t dist = std::sqrt(dist_sq);
    vec2 n = delta / dist;  // normalized collision normal

    vec2 v1 = velocity_;
    vec2 v2 = other.velocity();
    // relative velocity in normal direction
    real_t rel_vel = glm::dot(v1 - v2, n);
    if (rel_vel >= 0) {
        return;  // they are moving apart
    }

    // compute impulse scalar using masses
    real_t impulse = (2 * rel_vel) / (mass_ + other.mass());

    // update velocities (perfectly elastic collision)
    set_velocity(v1 - impulse * other.mass() * n);
    other.set_velocity(v2 + impulse * mass_ * n);
}  // NOLINTEND(readability-identifier-length)