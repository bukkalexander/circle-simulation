#pragma once

#include <string>
#include <vector>

#include "circle_simulation/cli_args.hpp"

class Cli {
   public:
    explicit Cli(const std::vector<std::string>& args);

    CliArgs get_args() const { return args_; }

    void print_help() const;

   private:
    bool parse_args(const std::vector<std::string>& args);

    CliArgs args_;
};
