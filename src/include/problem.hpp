#pragma once
#include "random_value_generator.hpp"
#include <string>

class Problem {
public:
  Problem(int user_id, std::string user_creation_date);
  friend std::ostream &operator<<(std::ostream &os, const Problem &problem);

private:
  RandomValueGenerator rvg{};
  std::string title{};
  std::string content{};
  std::string timestamp{}; // psql timestamp
  int user_id{};           // foreign key
  int id{};                // primary key
  static int id_counter;   // static variable used for id autoincrement
};