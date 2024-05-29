#include "include/review.hpp"
#include <string>

int Review::id_counter = 0;

Review::Review(std::string const &ride_date, int offer_id, int reviewed_id,
               int reviewer_id, std::string reviewer_age) {
  this->reviewed_id = reviewed_id;
  this->reviewer_id = reviewer_id;
  this->offer_id = offer_id;
  this->id = Review::id_counter++;
  std::string year = reviewer_age.substr(0, 4);
  int age = 2024 - std::stoi(year);
  if (age <= 24) {
    this->rating =
        rvg.get_weighted_random_int(1, 5, {0.05, 0.1, 0.15, 0.25, 0.45});
  } else if (age <= 30) {
    this->rating =
        rvg.get_weighted_random_int(1, 5, {0.05, 0.12, 0.13, 0.32, 0.38});
  } else if (age <= 40) {
    this->rating =
        rvg.get_weighted_random_int(1, 5, {0.05, 0.1, 0.15, 0.3, 0.4});
  } else if (age <= 50) {
    this->rating =
        rvg.get_weighted_random_int(1, 5, {0.05, 0.15, 0.25, 0.25, 0.3});
  } else {
    this->rating =
        rvg.get_weighted_random_int(1, 5, {0.1, 0.1, 0.25, 0.3, 0.25});
  }

  this->comment = rvg.get_random_review(this->rating);
  this->timestamp = rvg.get_random_date_bound(ride_date, 10);
}

std::ostream &operator<<(std::ostream &os, const Review &review) {
  std::ostringstream oss;
  oss << "INSERT INTO review (id, rating, comment, timestamp, reviewed_id, "
         "reviewer_id, "
         "offer_id) VALUES ("
      << review.id << ", " << review.rating << ", '" << review.comment << "', '"
      << review.timestamp << "', " << review.reviewed_id << ", "
      << review.reviewer_id << ", " << review.offer_id << ");";

  os << oss.str();
  return os;
}