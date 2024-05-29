#include "include/request.hpp"
#include <iostream>

int Request::id_counter = 0;

Request::Request(int from_user_id, int offer_id) {
  this->from_user_id = from_user_id;
  this->offer_id = offer_id;
  this->id = Request::id_counter++;
  this->state_id =
      rvg.get_weighted_random_int(0, 5, {0.13, 0.1, 0.14, 0.45, 0.18});
  switch (this->state_id) {
  case 0:
    this->accepted_by_offerer = false;
    this->accepted_by_submitter = rvg.get_random_int(0, 10) >= 5;
    break;
  case 1:
    this->accepted_by_offerer = false;
    this->accepted_by_submitter = rvg.get_random_int(0, 10) >= 3;
    break;
  case 2:
    this->accepted_by_offerer = rvg.get_random_int(0, 10) >= 5;
    this->accepted_by_submitter = rvg.get_random_int(0, 10) >= 5;
    break;
  default:
    this->accepted_by_offerer = true;
    this->accepted_by_submitter = true;
  }
}

std::ostream &operator<<(std::ostream &os, const Request &request) {
  std::ostringstream oss;
  oss << "INSERT INTO request (id, accepted_by_offerer, accepted_by_submitter, state_id, "
         "from_user_id, offer_id) VALUES ("
      << request.id << ", " << (request.accepted_by_offerer ? "true" : "false") << ", "
      <<( request.accepted_by_submitter ? "true" : "false") << ", " << request.state_id << ", "
      << request.from_user_id << ", " << request.offer_id << ");";

  os << oss.str();
  return os;
}