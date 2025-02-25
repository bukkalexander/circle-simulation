#pragma once

#include <glm/glm.hpp>

#include "circle_simulation/renderer.hpp"

class Circle {
    // SI units are used for state variables

   public:
    Circle(glm::vec2 position_, glm::vec2 velocity_, float radius_);
    void update(float time_step);
    void render(const Renderer& renderer) const;

   private:
    glm::vec2 position;
    glm::vec2 velocity;
    float radius;
};