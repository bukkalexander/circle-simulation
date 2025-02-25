#include "circle_simulation/simulation.hpp"

#include "circle_simulation/circle.hpp"
#include "circle_simulation/renderer.hpp"
#include "circle_simulation/types.hpp"
#include "circle_simulation/window.hpp"

Simulation::Simulation(Window& window, Renderer& renderer, const GlobalConfig& config)
    : window_(window),
      renderer_(renderer),
      ups_(config.ups),
      fps_(config.fps),
      time_step_(1.0 / config.ups) {
    circles_.emplace_back(vec2(3.0, 1.0), vec2(0.5, 0.0), 0.1, config);
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
