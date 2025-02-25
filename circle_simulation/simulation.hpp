#pragma once

#include <vector>

#include "circle_simulation/circle.hpp"
#include "circle_simulation/global_config.hpp"
#include "circle_simulation/renderer.hpp"
#include "circle_simulation/types.hpp"
#include "circle_simulation/window.hpp"

class Simulation {
   public:
    Simulation(Window& window, Renderer& renderer, const GlobalConfig& config);
    void run();

   private:
    void update();
    void render();

    Window& window_;
    Renderer& renderer_;
    real_t ups_;
    real_t fps_;
    real_t time_step_;
    std::vector<Circle> circles_;
};