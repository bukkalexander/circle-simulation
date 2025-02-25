#pragma once

#include <string>
#include <vector>

#include "circle_simulation/user_config.hpp"

class Cli {
   public:
    explicit Cli(const std::vector<std::string>& args);

    [[nodiscard]] UserConfig get_user_config() const { return user_config_; }

    void print_help() const;

   private:
    bool parse_args(const std::vector<std::string>& args);

    UserConfig user_config_;
};
