#include "include/search_timestamp.hpp"
#include "include/vars.hpp"

int SearchTimestamp::id_counter = 0;

SearchTimestamp::SearchTimestamp(int route_id) {
  this->searched_route_id = id;
  this->id = SearchTimestamp::id_counter++;
  this->timestamp =
      rvg.get_random_date(2018, 2024, vars::account_creation_weights);
}

std::ostream &operator<<(std::ostream &os,
                         const SearchTimestamp &searchTimestamp) {
  std::ostringstream oss;
  oss << "INSERT INTO search_timestamp (id, searched_route_id, timestamp) "
         "VALUES ("
      << searchTimestamp.id << ", " << searchTimestamp.searched_route_id
      << ", '" << searchTimestamp.timestamp << "');";

  os << oss.str();
  return os;
}