#pragma once
#include <chrono>
#include <string>
#include <utility>
#include <vector>

namespace util {
std::string
timepoint_to_string(const std::chrono::system_clock::time_point &timepoint);

std::string get_random_time(std::vector<double> weights);

std::string get_random_date(std::string const &start_date_str,
                            std::string const &end_date_str,
                            std::vector<double> weights);
std::string
timepoint_to_date(const std::chrono::system_clock::time_point &timepoint);

std::chrono::system_clock::time_point
date_to_timepoint(std::string const &date);

std::chrono::system_clock::time_point
date_to_timepoint(const std::string &date);



const  std::vector<double> hour_weights = {0.05, 0.04, 0.02, 0.02, 0.01, 0.01, 0,    0.03, 0.03,
         0.04, 0.04, 0.06, 0.06, 0.07, 0.06, 0.04, 0.06, 0.03,
         0.04, 0.05, 0.06, 0.05, 0.04, 0.04, 0.05
        };
} // namespace util