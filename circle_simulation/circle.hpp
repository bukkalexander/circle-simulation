#pragma once

#include "circle_simulation/renderer.hpp"
#include "circle_simulation/types.hpp"
#include "circle_simulation/world.hpp"

class Circle {
   public:
    Circle(vec2 position, vec2 velocity, real_t radius, const World& world);
    void update(real_t time_step);
    void render(const Renderer& renderer) const;

   private:
    vec2 position_;
    vec2 velocity_;
    real_t radius_;
    vec2 gravity_;
    const World& world_;
};