#include "include/util.hpp"

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
} // namespace util