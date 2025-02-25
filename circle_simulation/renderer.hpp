#pragma once

#include <glm/glm.hpp>

#include "circle_simulation/types.hpp"

class Renderer {
   public:
    Renderer(real_t left, real_t right, real_t bottom, real_t top);
    void draw_circle(vec2 center, real_t radius) const;
    void clear() const;
};