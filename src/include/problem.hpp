#pragma once
#include <string>

class Problem {
public:
private:
  std::string title{};
  std::string content{};
  std::string timestamp{}; // psql timestamp
  int user_id{};           // foreign key
  int id{};                // primary key
  static int id_counter;   // static variable used for id autoincrement
};