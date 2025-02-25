#include "circle_simulation/simulation.hpp"

#include "circle_simulation/circle.hpp"
#include "circle_simulation/consts.hpp"
#include "circle_simulation/renderer.hpp"
#include "circle_simulation/window.hpp"

Simulation::Simulation(Window& window, Renderer& renderer, float ups, float fps)
    : window_(window), renderer_(renderer), ups_(ups), fps_(fps) {
    time_step_ = 1.0F / ups_;
    circles_.emplace_back(glm::vec2(3.2F, 2.4F), glm::vec2(1.0F, 0.5F), 0.2F);
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
