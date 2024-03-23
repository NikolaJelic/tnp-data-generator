#pragma once
#include <string>

class Visit {
public:
private:
  int id{};                // primary key
  static int id_counter;   // static variable used for id autoincrement
  std::string timestamp{}; // psql timestamp
};