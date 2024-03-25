#include "include/random_value_generator.hpp"
#include <format>
#include <string_view>

std::string RandomValueGenerator::get_random_date(int start_year, int end_year,
                                                  std::vector<double> weights) {

  auto distributed_weights = distribute_weights(weights, end_year - start_year);

  double total_weight = 0.0;
  for (double w : weights) {
    total_weight += w;
  }
  if (std::abs(total_weight - 1.0) > 1e-6) {
    throw std::invalid_argument("Weights must sum up to 1.0");
  }

  std::discrete_distribution<int> year_dist(distributed_weights.begin(),
                                            distributed_weights.end());

  int year = std::min(start_year + year_dist(gen), end_year);
  std::uniform_int_distribution<int> month_dist(1, 12);
  int month = month_dist(gen);
  int day{};
  std::uniform_int_distribution<int> day_dist;

  int days_in_month;
  if (month == 2) {
    days_in_month =
        (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    days_in_month = 30;
  } else {
    days_in_month = 31;
  }
  day_dist = std::uniform_int_distribution<int>{1, days_in_month};

  day = day_dist(gen);
  auto time = get_random_time(vars::hour_weights);
  return std::format("{:04d}-{:02d}-{:02d} {}", year, month, day, time);
}

std::string RandomValueGenerator::get_random_time(std::vector<double> weights) {
  double total_weight = 0.0;
  for (double w : weights) {
    total_weight += w;
  }
  if (std::abs(total_weight - 1.0) > 1e-6) {
    throw std::invalid_argument("Weights must sum up to 1.0");
  }

  std::discrete_distribution<int> hour_dist(weights.begin(), weights.end());

  int random_hour = hour_dist(gen);

  std::uniform_int_distribution<int> minute_dist(0, 59);
  std::uniform_int_distribution<int> second_dist(0, 59);

  int random_minute = minute_dist(gen);
  int random_second = second_dist(gen);

  std::ostringstream formatted_time_stream;
  formatted_time_stream << std::setw(2) << std::setfill('0') << random_hour
                        << ":" << std::setw(2) << std::setfill('0')
                        << random_minute << ":" << std::setw(2)
                        << std::setfill('0') << random_second;

  return formatted_time_stream.str();
}

std::vector<double>
RandomValueGenerator::distribute_weights(std::vector<double> weights,
                                         int result_count) {
  double delta_weight = (double)result_count / weights.size();
  std::vector<double> normalized_weights{};
  for (auto w : weights) {
    for (int i = 0; i < delta_weight; ++i) {
      normalized_weights.push_back(w / delta_weight);
    }
  }
  // TODO: add lerping https://en.wikipedia.org/wiki/Linear_interpolation
  return normalized_weights;
}

int RandomValueGenerator::get_random_int(int min, int max) {
  std::uniform_int_distribution<int> dist(min, max);
  return dist(gen);
}

std::string RandomValueGenerator::get_random_name(bool is_male) {
  auto &names = is_male ? vars::male_names : vars::female_names;
  return names[get_random_int(0, names.size() - 1)];
}
std::string RandomValueGenerator::get_random_surname() {
  return vars::surnames[get_random_int(0, vars::surnames.size() - 1)];
}
std::string RandomValueGenerator::get_random_email(std::string const &name,
                                                   std::string const &surname) {
  int r = get_random_int(0, 99999);
  return name + (r < 5000 ? "_" : ".") + surname + std::to_string(r) +
         "@gmail.com";
}
std::string RandomValueGenerator::get_random_password() {
  std::stringstream ss;
  int length = get_random_int(9, 16);
  for (int i = 0; i < length; ++i) {
    ss << vars::alphanum.at(get_random_int(0, vars::alphanum.length() - 1));
  }
  return ss.str();
}

std::string RandomValueGenerator::get_random_city() {
  return vars::cities[get_random_int(0, vars::cities.size() - 1)];
}

std::string RandomValueGenerator::get_random_phone_number() {
  std::stringstream ss;
  ss << "06" << get_random_int(2, 6);
  for (int i = 0; i < 6; ++i) {
    ss << get_random_int(0, 9);
  }
  return ss.str();
}

std::string_view RandomValueGenerator::get_image_male() {
  std::string_view image =
      vars::male_images[get_random_int(0, vars::male_images.size() - 1)];
  return image;
}
std::string_view RandomValueGenerator::get_image_female() {
  std::string_view image =
      vars::female_images[get_random_int(0, vars::female_images.size() - 1)];
  return image;
}
