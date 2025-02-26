#pragma once

#include "circle_simulation/renderer.hpp"
#include "circle_simulation/types.hpp"
#include "circle_simulation/world.hpp"

class Circle {
   public:
    Circle(vec2 position, vec2 velocity, real_t radius, const World& world);
    void update(real_t time_step);
    void render(const Renderer& renderer) const;
    bool collides(const Circle& other) const;
    void resolve_collision(Circle& other);

    vec2 position() const { return position_; }
    vec2 velocity() const { return velocity_; }
    real_t radius() const { return radius_; }
    real_t mass() const { return mass_; }

    void set_velocity(vec2 velocity) { velocity_ = velocity; }

   private:
    vec2 position_;
    vec2 velocity_;
    const real_t radius_;
    const real_t mass_;
    const World& world_;
};