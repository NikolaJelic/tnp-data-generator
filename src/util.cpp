#include "include/util.hpp"

std::string Util::timepoint_to_string(
    const std::chrono::system_clock::time_point &timepoint) {
  std::stringstream ss;
  ss << timepoint;
  return ss.str();
}

std::chrono::year_month_day
Util::string_to_date(std::string const &date_string) {
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

std::string Util::timepoint_to_date(
    const std::chrono::system_clock::time_point &timepoint) {
  const auto ymd = std::chrono::floor<std::chrono::days>(timepoint);
  return std::format("{:%Y-%m-%d}", ymd);
}

std::chrono::system_clock::time_point
Util::date_to_timepoint(const std::string &date) {
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

std::string Util::get_random_date(int start_year, int end_year,
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
  auto time = get_random_time(hour_weights);
  std::stringstream ss;
  ss << year << "-" << std::setw(2) << std::setfill('0') << month << "-"
     << std::setw(2) << std::setfill('0') << day << " " << time;
  return ss.str();
}

std::string Util::get_random_time(std::vector<double> weights) {
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

std::vector<double> Util::distribute_weights(std::vector<double> weights,
                                             int result_count) {
  double delta_weight = (double)result_count / weights.size();
  std::vector<double> normalized_weights{};
  for (auto w : weights) {
    for (int i = 0; i < delta_weight; ++i) {
      normalized_weights.push_back(w / delta_weight);
    }
  }
  // TODO: add lerping
  return normalized_weights;
}

int Util::get_random_int(int min, int max) {
  std::uniform_int_distribution<int> dist(min, max);
  return dist(gen);
}
