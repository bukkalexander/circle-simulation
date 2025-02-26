#include "circle_simulation/circle_spawner.hpp"

constexpr int GENERATOR_SEED = 1337;

CircleSpawner::CircleSpawner(const World& world, const CircleSettings& settings)
    : world_(world),
      settings_(settings),
      gen_(GENERATOR_SEED),
      radius_dist_(settings_.min_circle_radius, settings_.max_circle_radius) {}

void CircleSpawner::update(std::vector<Circle>& circles) {
    update_counter_++;
    if (update_counter_ >= settings_.spawn_interval && spawned_count_ < settings_.spawn_limit) {
        update_counter_ = 0;
        real_t new_radius = radius_dist_(gen_);
        std::uniform_real_distribution<real_t> x_dist(world_.left() + new_radius,
                                                      world_.right() - new_radius);
        std::uniform_real_distribution<real_t> y_dist(world_.bottom() + new_radius,
                                                      world_.top() - new_radius);
        real_t new_x = x_dist(gen_);
        real_t new_y = y_dist(gen_);
        vec2 new_position(new_x, new_y);
        vec2 new_velocity(0.0, 0.0);
        circles.emplace_back(new_position, new_velocity, new_radius, world_);
        spawned_count_++;
    }
}
