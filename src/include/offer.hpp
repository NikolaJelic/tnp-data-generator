#pragma once

#include "random_value_generator.hpp"
#include <string>

class Offer {
public:
  Offer(int user_id, std::string const &min_date);
  friend std::ostream &operator<<(std::ostream &os, const Offer &offer);
  std::string get_publication_time() { return publication_date_time; }
  int get_free_seats() { return seats - taken_seats; }
  int get_id() { return id; }
  inline void fill_seat() { ++taken_seats; }
  int get_taken_seats() { return taken_seats; }
  void cancel() { is_canceled = true; }
  std::string get_departure() { return departure_date_time; }
  int get_driver() { return user_id; }

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