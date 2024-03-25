#include "include/problem.hpp"
#include "include/vars.hpp"

int Problem::id_counter = 0;

Problem::Problem(int user_id, std::string user_creation_date) {
  this->user_id = user_id;
  this->content = "I have a with a bug in your app";
  this->title = "Problem with app";
  this->id = Problem::id_counter++;
  this->timestamp = rvg.get_random_date_bound(user_creation_date, 500) +
                    rvg.get_random_time(vars::hour_weights);
}

std::ostream &operator<<(std::ostream &os, const Problem &problem) {
  std::ostringstream oss;
  oss << "INSERT INTO problem (id, title, content, timestamp, user_id) VALUES ("
      << problem.id << ", '" << problem.title << "', '" << problem.content
      << "', '" << problem.timestamp << "', " << problem.user_id << "');";

  os << oss.str();
  return os;
}