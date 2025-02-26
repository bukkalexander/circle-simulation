#include <iostream>
#include <string>

#include "circle_simulation/circle_settings.hpp"
#include "circle_simulation/circle_spawner.hpp"
#include "circle_simulation/cli.hpp"
#include "circle_simulation/config.hpp"
#include "circle_simulation/renderer.hpp"
#include "circle_simulation/sim_settings.hpp"
#include "circle_simulation/simulation.hpp"
#include "circle_simulation/window.hpp"
#include "circle_simulation/world.hpp"

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv, argv + argc);
    Cli cli(args);
    CliArgs cli_args = cli.get_args();
    Config config(cli_args);

    World world(config.window_width, config.window_height, config.pixels_per_meter, config.gravity);
    SimSettings sim_settings(config.fps, config.ups);
    CircleSettings circle_settings{config.spawn_limit, config.spawn_interval,
                                   config.min_circle_radius, config.max_circle_radius};

    CircleSpawner spawner(world, circle_settings);
    try {
        Window window(config.window_width, config.window_height, "Circle Simulation");
        Renderer renderer(config.window_left, config.window_right, config.window_bottom,
                          config.window_top);

        Simulation simulation(window, renderer, spawner, sim_settings);
        simulation.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return -1;
    }
}