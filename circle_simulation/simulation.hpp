#pragma once

#include <vector>

#include "circle_simulation/circle.hpp"
#include "circle_simulation/renderer.hpp"
#include "circle_simulation/sim_settings.hpp"
#include "circle_simulation/window.hpp"
#include "circle_simulation/world.hpp"

class Simulation {
   public:
    Simulation(Window& window, Renderer& renderer, const SimSettings& settings, const World& world);
    void run();

   private:
    void update(real_t time_step);
    void render();

    Window& window_;
    Renderer& renderer_;
    const SimSettings& settings_;
    std::vector<Circle> circles_;
};