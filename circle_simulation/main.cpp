#include <iostream>
#include <string>

#include "circle_simulation/cli.hpp"
#include "circle_simulation/global_config.hpp"
#include "circle_simulation/renderer.hpp"
#include "circle_simulation/simulation.hpp"
#include "circle_simulation/window.hpp"

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv, argv + argc);
    Cli cli(args);
    UserConfig user_config = cli.get_user_config();
    GlobalConfig config(user_config);
    std::string window_title = "Circle Simulation";

    try {
        Window window(config.window_width, config.window_height, window_title);
        Renderer renderer(config.window_left, config.window_right, config.window_bottom,
                          config.window_top);
        Simulation simulation(window, renderer, config);
        simulation.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return -1;
    }
}