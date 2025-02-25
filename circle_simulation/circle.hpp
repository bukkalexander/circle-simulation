#pragma once

#include "circle_simulation/global_config.hpp"
#include "circle_simulation/renderer.hpp"
#include "circle_simulation/types.hpp"

class Circle {
    // SI units are used for state variables

   public:
    Circle(vec2 position, vec2 velocity, real_t radius, const GlobalConfig& config);
    void update(real_t time_step);
    void render(const Renderer& renderer) const;

   private:
    vec2 position_;
    vec2 velocity_;
    real_t radius_;
    vec2 gravity_;
    const real_t world_left_;
    const real_t world_right_;
    const real_t world_bottom_;
    const real_t world_top_;
    const real_t world_width_;
    const real_t world_height_;
    const real_t meters_to_pixels_;
};