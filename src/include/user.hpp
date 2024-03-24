#pragma once

#include "random_value_generator.hpp"
#include "util.hpp"
#include <string>
class User {
public:
  User();
  friend std::ostream &operator<<(std::ostream &os, const User &user);

private:
  static inline RandomValueGenerator rvg{};

  std::string name{};
  std::string surname{};
  std::string
      birth_date{}; // needs date conversion into appropriate psql format
  std::string city{};
  std::string email{};
  std::string password{};
  std::string phone_number{}; // format like real phone numbers
  std::string image{};
  bool is_verified = {false};
  std::string created_at{}; // psql timestamp
  bool gender{};            // male  = true,  female = false
  bool is_disabled{false};
  int id{};              // primary key
  static int id_counter; // static variable used for id autoincrement
};

