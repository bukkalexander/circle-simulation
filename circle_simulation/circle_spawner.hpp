#pragma once

#include <random>
#include <vector>

#include "circle_simulation/circle.hpp"
#include "circle_simulation/circle_settings.hpp"
#include "circle_simulation/types.hpp"
#include "circle_simulation/world.hpp"

class CircleSpawner {
   public:
    CircleSpawner(const World& world, const CircleSettings& settings);
    void update(std::vector<Circle>& circles);

   private:
    bool candidate_collides(const std::vector<Circle>& circles, const Circle& candidate) const;
    vec2 generate_candidate_position(real_t candidate_radius) const;

    const World& world_;
    const CircleSettings settings_;
    int update_counter_ = 0;
    int spawned_count_ = 0;
    mutable std::mt19937 gen_;
    std::uniform_real_distribution<real_t> radius_dist_;
};
