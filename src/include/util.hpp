#pragma once
#include <chrono>
#include <cstddef>
#include <random>
#include <string>
#include <vector>

namespace util {
std::string
timepoint_to_string(const std::chrono::system_clock::time_point &timepoint);

std::chrono::year_month_day string_to_date(std::string const &date_string);

std::string
timepoint_to_date(const std::chrono::system_clock::time_point &timepoint);
std::string date_to_string(const std::chrono::year_month_day &date);
std::chrono::system_clock::time_point
date_to_timepoint(std::string const &date);

} // namespace util