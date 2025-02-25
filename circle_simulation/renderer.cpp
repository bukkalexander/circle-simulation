#include "circle_simulation/renderer.hpp"

#include <GL/gl.h>

#include <cmath>
#include <glm/glm.hpp>

#include "circle_simulation/types.hpp"

Renderer::Renderer(real_t left, real_t right, real_t bottom, real_t top) {
    // Set up a 2D orthographic projection:
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(left, right, bottom, top, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// NOLINTBEGIN(readability-convert-member-functions-to-static)

void Renderer::draw_circle(vec2 center, real_t radius) const {
    glColor3d(1.0, 0.0, 0.0);
    constexpr int NUM_SEGMENTS = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(center.x, center.y);  // center vertex
    for (int i = 0; i <= NUM_SEGMENTS; ++i) {
        constexpr real_t math_pi = 3.14159265358979323846;
        constexpr real_t whole_circle_rad = 2.0 * math_pi;
        real_t theta = whole_circle_rad * (real_t)i / NUM_SEGMENTS;
        real_t x_offset = radius * cos(theta);
        real_t y_offset = radius * sin(theta);
        glVertex2d(center.x + x_offset, center.y + y_offset);
    }
    glEnd();
}

void Renderer::clear() const { glClear(GL_COLOR_BUFFER_BIT); }

// NOLINTEND(readability-convert-member-functions-to-static)