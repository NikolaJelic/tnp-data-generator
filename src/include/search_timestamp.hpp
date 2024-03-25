#pragma once
#include "random_value_generator.hpp"
#include <string>

class SearchTimestamp {
public:
  SearchTimestamp(int route_id);
  friend std::ostream &operator<<(std::ostream &os,
                                  const SearchTimestamp &searchTimestamp);

private:
  RandomValueGenerator rvg{};
  int id{};                // primary key
  static int id_counter;   // static variable used for id autoincrement
  int searched_route_id{}; // foreign key
  std::string timestamp{}; // psql timestamp
};