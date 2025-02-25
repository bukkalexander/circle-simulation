#include "circle_simulation/renderer.hpp"

#include <GL/gl.h>

#include <cmath>
#include <glm/glm.hpp>

Renderer::Renderer(int left, int right, int bottom, int top) {
    // Set up a 2D orthographic projection:
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(left, right, bottom, top, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// NOLINTBEGIN(readability-convert-member-functions-to-static)

void Renderer::draw_circle(glm::vec2 center, float radius) const {
    glColor3f(1.0F, 0.0F, 0.0F);
    constexpr int NUM_SEGMENTS = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(center.x, center.y);  // center vertex
    for (int i = 0; i <= NUM_SEGMENTS; ++i) {
        constexpr float math_pi = 3.1415926F;
        constexpr float whole_circle_rad = 2.0F * math_pi;
        float theta = whole_circle_rad * (float)i / NUM_SEGMENTS;
        float x_offset = radius * cosf(theta);
        float y_offset = radius * sinf(theta);
        glVertex2f(center.x + x_offset, center.y + y_offset);
    }
    glEnd();
}

void Renderer::clear() const { glClear(GL_COLOR_BUFFER_BIT); }

// NOLINTEND(readability-convert-member-functions-to-static)