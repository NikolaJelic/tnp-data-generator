#pragma once
#include <string>

class Review {
public:
private:
  int id{};              // primary key
  static int id_counter; // static variable used for id autoincrement
  int rating{};          // 1-5
  std::string comment{};
  std::string timestamp; // psql timestamp
  int reviewed_id{};     // foreign key
  int reviewer_id{};     // foreign key
  int offer_id{};        // foreign key
};