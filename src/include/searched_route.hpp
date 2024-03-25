#pragma once
#include "random_value_generator.hpp"
#include <string>

class SearchedRoute {
public:
  SearchedRoute();

  friend std::ostream &operator<<(std::ostream &os,
                                  const SearchedRoute &searchedRoute);
  friend bool operator==(const SearchedRoute &lhs, const SearchedRoute &rhs);
  inline int get_id() { return id; }

private:
  RandomValueGenerator rvg{};
  std::string start{};
  std::string end{};
  int id{};              // primary key
  static int id_counter; // static variable used for id autoincrement
};