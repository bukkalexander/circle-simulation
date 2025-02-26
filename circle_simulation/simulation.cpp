#include "circle_simulation/simulation.hpp"

#include <chrono>
#include <iostream>

#include "circle_simulation/circle.hpp"
#include "circle_simulation/circle_spawner.hpp"
#include "circle_simulation/renderer.hpp"
#include "circle_simulation/sim_settings.hpp"
#include "circle_simulation/types.hpp"
#include "circle_simulation/window.hpp"

Simulation::Simulation(Window& window, Renderer& renderer, CircleSpawner& spawner,
                       const SimSettings& settings)
    : window_(window), renderer_(renderer), spawner_(spawner), settings_(settings) {}

void Simulation::update(real_t time_step) {
    spawner_.update(circles_);

    for (auto& circle : circles_) {
        circle.update(time_step);
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
    using clock = std::chrono::steady_clock;

    auto cycle_start_time = clock::now();

    auto last_update_time = cycle_start_time;
    auto last_render_time = cycle_start_time;

    int update_count = 0;
    int render_count = 0;

    const double target_update_period = 1.0 / settings_.ups;
    const double target_render_period = 1.0 / settings_.fps;

    while (!window_.shouldClose()) {
        auto current_time = clock::now();

        double time_since_last_update =
            std::chrono::duration<double>(current_time - last_update_time).count();
        double time_since_last_render =
            std::chrono::duration<double>(current_time - last_render_time).count();

        if (time_since_last_update >= target_update_period) {
            update(time_since_last_update);
            last_update_time = current_time;
            update_count++;
        }

        if (time_since_last_render >= target_render_period) {
            render();
            last_render_time = current_time;
            render_count++;
        }

        Window::pollEvents();

        double cycle_duration =
            std::chrono::duration<double>(clock::now() - cycle_start_time).count();
        if (cycle_duration >= 1.0) {
            double average_ups = update_count / cycle_duration;
            double average_fps = render_count / cycle_duration;
            std::cout << "UPS: " << average_ups << ", FPS: " << average_fps << '\n';
            update_count = 0;
            render_count = 0;
            cycle_start_time = clock::now();
            last_update_time = cycle_start_time;
            last_render_time = cycle_start_time;
        }
    }
}
