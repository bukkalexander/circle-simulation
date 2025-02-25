#pragma once

#include <glm/glm.hpp>

class Renderer {
   public:
    Renderer(int left, int right, int bottom, int top);
    void draw_circle(glm::vec2 center, float radius) const;
    void clear() const;
};