#pragma once
#include "random_value_generator.hpp"
#include <string>

class Review {
public:
  Review(std::string const &ride_date, int offer_id, int reviewed_id,
         int reviewer_id, std::string reviewer_age);
  friend std::ostream &operator<<(std::ostream &os, const Review &review);

private:
  RandomValueGenerator rvg{};
  int id{};              // primary key
  static int id_counter; // static variable used for id autoincrement
  int rating{};          // 1-5
  std::string comment{};
  std::string timestamp; // psql timestamp
  int reviewed_id{};     // foreign key
  int reviewer_id{};     // foreign key
  int offer_id{};        // foreign key
};