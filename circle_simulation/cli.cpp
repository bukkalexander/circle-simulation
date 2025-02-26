#include "cli.hpp"

#include <cstdlib>
#include <iostream>

Cli::Cli(const std::vector<std::string>& args) {
    if (!parse_args(args)) {
        print_help();
        std::exit(EXIT_FAILURE);
    }
}

void Cli::print_help() const {
    std::cout << "Usage: ./circle_simulation [options]\n"
              << "Options:\n"
              << "  --window_width <int>       Window width in pixels (default: 640)\n"
              << "  --window_height <int>      Window height in pixels (default: 480)\n"
              << "  --min_radius <double>      Minimum circle radius in meters (default: 0.1)\n"
              << "  --max_radius <double>      Maximum circle radius in meters (default: 0.3)\n"
              << "  --spawn_limit <int>        Maximum number of circles to spawn (default: 100)\n"
              << "  --spawn_interval <int>     number of updates between spawns (default: 100)\n"
              << "  --gravity <double>         Gravity acceleration (default: 9.8)\n"
              << "  --fps <int>                Frames per second (default: 60)\n"
              << "  --ups <int>                Updates per second (default: 1000)\n"
              << "  --help                     Print this help message\n"
              << "\nExample:\n"
              << "  ./circle_simulation --window_width 800 --window_height 600 "
                 "--min_radius 0.05 --max_radius 0.25 --spawn_limit 20 "
                 "--spawn_interval 200 --gravity 9.81 --fps 75 --ups 90\n";
}

bool Cli::parse_args(const std::vector<std::string>& args) {
    for (size_t i = 1; i < args.size(); ++i) {
        const std::string& arg = args[i];
        if (arg == "--window_width" && i + 1 < args.size()) {
            args_.window_width = std::atoi(args[++i].c_str());
        } else if (arg == "--window_height" && i + 1 < args.size()) {
            args_.window_height = std::atoi(args[++i].c_str());
        } else if (arg == "--min_radius" && i + 1 < args.size()) {
            args_.min_circle_radius = std::atof(args[++i].c_str());
        } else if (arg == "--max_radius" && i + 1 < args.size()) {
            args_.max_circle_radius = std::atof(args[++i].c_str());
        } else if (arg == "--spawn_limit" && i + 1 < args.size()) {
            args_.spawn_limit = std::atoi(args[++i].c_str());
        } else if (arg == "--spawn_interval" && i + 1 < args.size()) {
            args_.spawn_interval = std::atoi(args[++i].c_str());
        } else if (arg == "--gravity" && i + 1 < args.size()) {
            args_.gravity = std::atof(args[++i].c_str());
        } else if (arg == "--fps" && i + 1 < args.size()) {
            args_.fps = std::atoi(args[++i].c_str());
        } else if (arg == "--ups" && i + 1 < args.size()) {
            args_.ups = std::atoi(args[++i].c_str());
        } else if (arg == "--help") {
            return false;
        } else {
            std::cerr << "Unknown option: " << arg << "\n";
            return false;
        }
    }
    return true;
}
