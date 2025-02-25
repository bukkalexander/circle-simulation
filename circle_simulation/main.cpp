#include <iostream>
#include <string>

#include "circle_simulation/consts.hpp"
#include "circle_simulation/renderer.hpp"
#include "circle_simulation/simulation.hpp"
#include "circle_simulation/window.hpp"

int main() {
    std::string window_title = "Circle Simulation";
    try {
        Window window(consts::WINDOW_WIDTH, consts::WINDOW_HEIGHT, window_title);
        Renderer renderer(consts::WINDOW_LEFT, consts::WINDOW_RIGHT, consts::WINDOW_BOTTOM,
                          consts::WINDOW_TOP);
        Simulation simulation(window, renderer, consts::UPS, consts::FPS);
        simulation.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return -1;
    }
}