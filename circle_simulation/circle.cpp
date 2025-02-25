#include "circle_simulation/circle.hpp"

#include <glm/glm.hpp>
#include <iostream>

#include "circle_simulation/consts.hpp"

Circle::Circle(glm::vec2 position_, glm::vec2 velocity_, float radius_)
    : position(position_), velocity(velocity_), radius(radius_) {}

void Circle::update(float time_step) {
    position = glm::vec2(1.0F, 1.0F);
    std::cout << time_step << '\n';
    std::cout << position.x << position.y << '\n';
}

void Circle::render(const Renderer& renderer) const {
    renderer.draw_circle(position * consts::METERS_TO_PIXELS, radius * consts::METERS_TO_PIXELS);
}
