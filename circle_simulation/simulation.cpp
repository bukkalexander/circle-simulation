#include "circle_simulation/simulation.hpp"

#include "circle_simulation/circle.hpp"
#include "circle_simulation/renderer.hpp"
#include "circle_simulation/sim_settings.hpp"
#include "circle_simulation/types.hpp"
#include "circle_simulation/window.hpp"
#include "circle_simulation/world.hpp"

Simulation::Simulation(Window& window, Renderer& renderer, const SimSettings& settings,
                       const World& world)
    : window_(window), renderer_(renderer), settings_(settings) {
    circles_.emplace_back(vec2(3.0, 1.0), vec2(0.5, 0.0), 0.1, world);
}

void Simulation::update() {
    for (auto& circle : circles_) {
        circle.update(settings_.time_step);
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
