#pragma once
#include "random_value_generator.hpp"
#include <string>

class Visit {
public:
  Visit();
  friend std::ostream &operator<<(std::ostream &os, const Visit &visit);

private:
  RandomValueGenerator rvg{};
  int id{};                // primary key
  static int id_counter;   // static variable used for id autoincrement
  std::string timestamp{}; // psql timestamp
};