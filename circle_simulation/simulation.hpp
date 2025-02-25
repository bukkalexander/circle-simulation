#pragma once

#include <vector>

#include "circle_simulation/circle.hpp"
#include "circle_simulation/renderer.hpp"
#include "circle_simulation/window.hpp"

class Simulation {
   public:
    Simulation(Window& window, Renderer& renderer, float ups, float fps);
    void run();

   private:
    void update();
    void render();

    Window& window_;
    Renderer& renderer_;
    float ups_;
    float fps_;
    float time_step_;
    std::vector<Circle> circles_;
};