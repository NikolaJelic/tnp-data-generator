#include "include/util.hpp"

namespace util {
constexpr std::string
timepoint_to_string(const std::chrono::system_clock::time_point &timepoint);
    std::string timepoint_to_date(const std::chrono::system_clock::time_point &timepoint) {
        // Convert time_point to time_t
        std::time_t time = std::chrono::system_clock::to_time_t(timepoint);

        // Format the time_t value into a string compatible with PostgreSQL
        std::stringstream ss;
        ss << std::put_time(std::gmtime(&time), "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }

    std::chrono::system_clock::time_point date_to_timepoint(const std::string &date) {
        std::istringstream iss(date);

        int year, month, day, hour, minute, second;
        char delimiter;
        iss >> year >> delimiter >> month >> delimiter >> day >> delimiter >> hour >> delimiter >> minute >> delimiter >> second;

        // Create a tm structure in UTC time
        std::tm tm_time = {};
        tm_time.tm_year = year - 1900; // Years since 1900
        tm_time.tm_mon = month - 1;     // Months since January (0-based)
        tm_time.tm_mday = day;          // Day of the month
        tm_time.tm_hour = hour;         // Hours since midnight
        tm_time.tm_min = minute;        // Minutes after the hour
        tm_time.tm_sec = second;        // Seconds after the minute

        // Convert tm structure to time_point
        std::time_t time = std::mktime(&tm_time);
        return std::chrono::system_clock::from_time_t(time);
    }

constexpr std::chrono::system_clock::time_point
get_random_timepoint_hours(std::size_t start_h, std::size_t end_h,
                           std::vector<std::pair<int, float>> const &weights);
constexpr std::string get_random_date(std::string const &start_date,
                                      std::string const &end_date);

}