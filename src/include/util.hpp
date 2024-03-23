#pragma once
#include <chrono>
#include <string>
#include <utility>
#include <vector>

namespace util {
constexpr std::string
timepoint_to_string(const std::chrono::system_clock::time_point &timepoint);

constexpr std::chrono::system_clock::time_point
get_random_timepoint_hours(std::size_t start_h, std::size_t end_h,
                           std::vector<std::pair<int, float>> const &weights);

constexpr std::string get_random_date(std::string const &start_date,
                                      std::string const &end_date);
std::string
timepoint_to_date(const std::chrono::system_clock::time_point &timepoint);

std::chrono::system_clock::time_point
date_to_timepoint(std::string const &date);

} // namespace util