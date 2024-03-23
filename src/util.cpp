#include "include/util.hpp"
#include <chrono>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

namespace util {
std::string
timepoint_to_string(const std::chrono::system_clock::time_point &timepoint) {
  std::stringstream ss;
  ss << timepoint;
  return ss.str();
}

std::chrono::year_month_day string_to_date(std::string const &date_string) {
  std::istringstream iss(date_string);

  int year, month, day;
  char delimiter;

  iss >> year >> delimiter >> month >> delimiter >> day;

  std::chrono::year_month_day ymd{
      std::chrono::year{year},
      std::chrono::month{static_cast<unsigned int>(month)},
      std::chrono::day{static_cast<unsigned int>(day)}};
  return ymd;
}

std::string
timepoint_to_date(const std::chrono::system_clock::time_point &timepoint) {
  const auto ymd = std::chrono::floor<std::chrono::days>(timepoint);
  return std::format("{:%Y-%m-%d}", ymd);
}

std::chrono::system_clock::time_point
date_to_timepoint(const std::string &date) {
  std::istringstream iss(date);

  std::size_t year;
  std::size_t month;
  std::size_t day;
  char delimiter;
  iss >> year >> delimiter >> month >> delimiter >> day;

  std::chrono::year_month_day ymd{
      std::chrono::year{static_cast<int>(year)},
      std::chrono::month{static_cast<unsigned int>(month)},
      std::chrono::day{static_cast<unsigned int>(day)}};

  auto sys_days = std::chrono::sys_days{ymd};
  return std::chrono::system_clock::from_time_t(
      std::chrono::system_clock::to_time_t(sys_days));
}



std::string get_random_date(std::string const &month_str,
                            std::vector<double> weights) {}

std::string get_random_time(std::vector<double> weights) {
  double total_weight = 0.0;
  for (double w : weights) {
    total_weight += w;
  }
  if (std::abs(total_weight - 1.0) > 1e-6) {
    throw std::invalid_argument("Weights must sum up to 1.0");
  }

  std::random_device rd;
  std::mt19937 gen(rd());

  std::discrete_distribution<int> hour_dist(weights.begin(), weights.end());

  int random_hour = hour_dist(gen);

  std::uniform_int_distribution<int> minute_dist(0, 59);
  std::uniform_int_distribution<int> second_dist(0, 59);

  int random_minute = minute_dist(gen);
  int random_second = second_dist(gen);

  std::string formatted_time = std::to_string(random_hour) + ":" +
                               std::to_string(random_minute) + ":" +
                               std::to_string(random_second);
  return formatted_time;
}

} // namespace util