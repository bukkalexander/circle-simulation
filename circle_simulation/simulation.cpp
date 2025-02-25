#include "circle_simulation/simulation.hpp"

#include "circle_simulation/circle.hpp"
#include "circle_simulation/consts.hpp"
#include "circle_simulation/renderer.hpp"
#include "circle_simulation/window.hpp"

Simulation::Simulation(Window& window, Renderer& renderer, float ups, float fps)
    : window_(window), renderer_(renderer), ups_(ups), fps_(fps) {
    time_step_ = 1.0F / ups_;
    circles_.emplace_back(
        glm::vec2(consts::WINDOW_WIDTH / 2.0F * consts::PIXELS_TO_METERS,
                  (consts::WINDOW_HEIGHT - consts::WINDOW_TOP) * consts::PIXELS_TO_METERS),
        glm::vec2(0.0F, 0.0F), 0.1F);
}

void Simulation::update() {
    for (auto& circle : circles_) {
        circle.update(time_step_);
    }
}

void Simulation::render() {
    renderer_.clear();
    for (const auto& circle : circles_) {
        circle.render(renderer_);
    }
    window_.swapBuffers();
}

void Simulation::run() {
    while (!window_.shouldClose()) {
        update();
        render();
        Window::pollEvents();
    }
}
