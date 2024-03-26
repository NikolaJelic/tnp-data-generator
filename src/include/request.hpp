#pragma once

#include "random_value_generator.hpp"
class Request {
public:
  Request(int from_user_id, int offer_id);
  friend std::ostream &operator<<(std::ostream &os, const Request &request);
  int get_status() { return state_id; }

private:
  RandomValueGenerator rvg{};
  int id{};              // primary key
  static int id_counter; // static variable used for id autoincrement
  bool accepted_by_offerer{false};
  bool accepted_by_submitter{false};
  int state_id{};     // foreign key
  int from_user_id{}; // foreign key
  int offer_id{};     // foreign key
};