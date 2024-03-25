#pragma once

#include "random_value_generator.hpp"
#include <string>
class Offer {
public:
  Offer(int user_id);
  friend std::ostream &operator<<(std::ostream &os, const Offer &offer);

private:
  RandomValueGenerator rvg{};
  std::string start{}; // location
  std::string end{};   // location
  float price{};       // 2 decimal places
  int seats{};
  int taken_seats{};
  std::string vehicle{};
  std::string description{};
  std::string publication_date_time{}; // psql timestamp
  std::string departure_date_time{};   // psql timestamp
  bool is_canceled{false};
  int user_id{};         // foreign key
  int id{};              // primary key
  static int id_counter; // static variable used for id autoincrement
};