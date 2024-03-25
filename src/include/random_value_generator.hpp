#pragma once
#include "vars.hpp"
#include <iomanip>
#include <random>
#include <sstream>
#include <string>
#include <vector>

class RandomValueGenerator {
public:
  RandomValueGenerator() : gen(std::random_device()()) {}

  std::string get_random_time(std::vector<double> weights);

  std::string get_random_date(int start_year, int end_year,
                              std::vector<double> weights);
  std::string get_random_date_bound(std::string const &start, int offset_days);

  std::vector<double> distribute_weights(std::vector<double> weights,
                                         int result_count);
  int get_random_int(int min, int max);
  int get_weighted_random_int(int min, int max, std::vector<double> weights);
  std::string get_random_name(bool is_male);
  std::string get_random_surname();
  std::string get_random_email(std::string const &name,
                               std::string const &surname);
  std::string get_random_password();
  std::string get_random_city();
  std::string get_random_phone_number();
  std::string_view get_image_male();
  std::string_view get_image_female();
  std::string get_random_review(int rating);
  std::string get_random_vehicle();

private:
  std::mt19937 gen;
};