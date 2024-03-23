#pragma once
#include <string>

class Notification {
public:
private:
  std::string content{};
  std::string timestamp{}; // psql timestamp
  bool is_read{false};
  int user_id{};         // foreign key
  int id{};              // primary key
  static int id_counter; // static variable used for id autoincrement
};