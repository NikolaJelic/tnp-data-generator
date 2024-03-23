#pragma once

class Request {
public:
private:
  int id{};              // primary key
  static int id_counter; // static variable used for id autoincrement
  bool accepted_by_offerer{false};
  bool accepted_by_submitter{false};
  int state_it{};     // foreign key
  int from_user_id{}; // foreign key
  int offer_id{};     // foreign key
};