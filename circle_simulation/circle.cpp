#include "circle_simulation/circle.hpp"

#include "circle_simulation/global_config.hpp"
#include "circle_simulation/types.hpp"
#include "circle_simulation/utils.hpp"

// NOLINTBEGIN (bugprone-easily-swappable-parameters)
Circle::Circle(vec2 position, vec2 velocity, real_t radius, const GlobalConfig& config)
    : position_(position),
      velocity_(velocity),
      radius_(radius),
      gravity_(0.0, -config.gravity),
      world_left_(config.window_left * config.pixels_to_meters),
      world_right_(config.window_right * config.pixels_to_meters),
      world_bottom_(config.window_top * config.pixels_to_meters),
      world_top_(config.window_bottom * config.pixels_to_meters),
      world_width_(config.window_width * config.pixels_to_meters),
      world_height_(config.window_height * config.pixels_to_meters),
      meters_to_pixels_(config.meters_to_pixels) {}
// NOLINTEND (bugprone-easily-swappable-parameters)

void Circle::update(real_t time_step) {
    velocity_ += gravity_ * time_step;
    position_ += velocity_ * time_step;

    // Check left/right collisions:
    if (position_.x - radius_ < world_left_) {
        position_.x = world_left_ + radius_;  // reposition inside the left boundary
        velocity_.x = -velocity_.x;           // reflect horizontal velocity
    } else if (position_.x + radius_ > world_right_) {
        position_.x = world_right_ - radius_;  // reposition inside the right boundary
        velocity_.x = -velocity_.x;
    }

    // Check bottom/top collisions:
    if (position_.y - radius_ < world_bottom_) {
        position_.y = world_bottom_ + radius_;  // reposition above the bottom boundary
        velocity_.y = -velocity_.y;
    } else if (position_.y + radius_ > world_top_) {
        position_.y = world_top_ - radius_;  // reposition below the top boundary
        velocity_.y = -velocity_.y;
    }
}

void Circle::render(const Renderer& renderer) const {
    renderer.draw_circle(utils::world_to_pixel_vec2(position_, meters_to_pixels_, world_height_),
                         utils::world_to_pixel_radius(radius_, meters_to_pixels_));
}
