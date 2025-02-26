#pragma once

#include <vector>

#include "circle_simulation/circle.hpp"
#include "circle_simulation/circle_spawner.hpp"
#include "circle_simulation/renderer.hpp"
#include "circle_simulation/sim_settings.hpp"
#include "circle_simulation/window.hpp"

class Simulation {
   public:
    Simulation(Window& window, Renderer& renderer, CircleSpawner& spawner,
               const SimSettings& settings);
    void run();

   private:
    void update(real_t time_step);
    void render();

    Window& window_;
    Renderer& renderer_;
    CircleSpawner& spawner_;
    const SimSettings& settings_;

    std::vector<Circle> circles_;
};