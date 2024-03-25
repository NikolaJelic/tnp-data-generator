#include "include/visit.hpp"
#include "include/vars.hpp"

int Visit::id_counter = 0;

Visit::Visit() {
  this->id = Visit::id_counter++;
  this->timestamp = rvg.get_random_date(2018, 2024, vars::year_weights);
}

std::ostream &operator<<(std::ostream &os, const Visit &visit) {
  std::ostringstream oss;
  oss << "INSERT INTO visit (id, timestamp) VALUES (" << visit.id << ", '"
      << visit.timestamp << "');";

  os << oss.str();
  return os;
}