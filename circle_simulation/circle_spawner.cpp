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
        for (int attempt = 0; attempt < settings_.spawn_max_retries; ++attempt) {
            real_t new_radius = radius_dist_(gen_);
            vec2 candidate_pos = generate_candidate_position(new_radius);
            Circle candidate(candidate_pos, vec2(0.0, 0.0), new_radius, world_);
            if (!candidate_collides(circles, candidate)) {
                circles.push_back(candidate);
                spawned_count_++;
                break;
            }
        }
    }
}

bool CircleSpawner::candidate_collides(const std::vector<Circle>& circles,
                                       const Circle& candidate) const {
    for (const auto& circle : circles) {  // NOLINT(readability-use-anyofallof)
        if (circle.collides(candidate)) {
            return true;
        }
    }
    return false;
}

vec2 CircleSpawner::generate_candidate_position(real_t candidate_radius) const {
    std::uniform_real_distribution<real_t> x_dist(world_.left() + candidate_radius,
                                                  world_.right() - candidate_radius);
    std::uniform_real_distribution<real_t> y_dist(world_.bottom() + candidate_radius,
                                                  world_.top() - candidate_radius);
    return {x_dist(gen_), y_dist(gen_)};
}
