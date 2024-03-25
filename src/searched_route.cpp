#include "include/searched_route.hpp"

int SearchedRoute::id_counter = 0;

SearchedRoute::SearchedRoute() {
  this->id = SearchedRoute::id_counter++;
  this->start = this->rvg.get_random_city();
  this->end = this->rvg.get_random_city();
}

std::ostream &operator<<(std::ostream &os, const SearchedRoute &searchedRoute) {
  std::ostringstream oss;
  oss << "INSERT INTO searched_route (id, start, end) VALUES ("
      << searchedRoute.id << ", '" << searchedRoute.start << "', '"
      << searchedRoute.end << "');";

  os << oss.str();
  return os;
}

bool operator==(const SearchedRoute &lhs, const SearchedRoute &rhs) {
  return lhs.start == rhs.start && lhs.end == rhs.end;
}