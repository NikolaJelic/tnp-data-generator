#pragma once
#include <chrono>
#include <cstddef>
#include <random>
#include <string>
#include <vector>


class Util {
public:
  Util() : gen(std::random_device()()) {}
  std::string
  timepoint_to_string(const std::chrono::system_clock::time_point &timepoint);

  std::chrono::year_month_day string_to_date(std::string const &date_string);
  std::string get_random_time(std::vector<double> weights);

  std::string get_random_date(int start_year, int end_year,
                              std::vector<double> weights);
  std::string
  timepoint_to_date(const std::chrono::system_clock::time_point &timepoint);

  std::chrono::system_clock::time_point
  date_to_timepoint(std::string const &date);

  std::vector<double> distribute_weights(std::vector<double> weights,
                                         int result_count);
  int get_random_int(int min, int max);

private:
  std::mt19937 gen;

  const std::vector<double> hour_weights = {
      0.05, 0.04, 0.02, 0.02, 0.01, 0.01, 0,    0.03, 0.03,
      0.04, 0.04, 0.06, 0.06, 0.07, 0.06, 0.04, 0.06, 0.03,
      0.04, 0.05, 0.06, 0.05, 0.04, 0.04, 0.05};
};