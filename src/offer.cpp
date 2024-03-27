#include "include/offer.hpp"

int Offer::id_counter = 0;
Offer::Offer(int user_id, std::string const &min_date) {
  this->user_id = user_id;
  this->id = Offer::id_counter++;
  this->publication_date_time = rvg.get_random_date_bound(min_date, 1000);
  this->departure_date_time =
      rvg.get_random_date_bound(publication_date_time, 20);
  this->seats = rvg.get_random_int(2, 4);
  this->taken_seats = 0;
  this->description = "";
  this->price = rvg.get_random_int(5, 30);
  this->start = rvg.get_random_city();
  this->end = rvg.get_random_city();
  this->vehicle = rvg.get_random_vehicle();
}

std::ostream &operator<<(std::ostream &os, const Offer &offer) {
  std::ostringstream oss;
  oss << "INSERT INTO offer (id, \"start\", \"end\", price, seats, taken_seats, "
         "vehicle, description, "
      << "publication_date_time, departure_date_time, is_canceled, user_id, encoded_path) "
         "VALUES ("
      << offer.id << ", '" << offer.start << "', '" << offer.end << "', "
      << offer.price << ", " << offer.seats << ", " << offer.taken_seats
      << ", '" << offer.vehicle << "', '" << offer.description << "', '"
      << offer.publication_date_time << "', '" << offer.departure_date_time
      << "', " << (offer.is_canceled ? "true" : "false") << ", " << offer.user_id << ", '');";

  os << oss.str();
  return os;
}