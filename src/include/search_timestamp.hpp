#pragma once
#include <string>

class SearchTimestamp {
public:
private:
  int id{};                // primary key
  static int id_counter;   // static variable used for id autoincrement
  int searched_route_id{}; // foreign key
  std::string timestamp{}; // psql timestamp
};