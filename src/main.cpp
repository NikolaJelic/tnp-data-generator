#include "include/offer.hpp"
#include "include/problem.hpp"
#include "include/random_value_generator.hpp"
#include "include/request.hpp"
#include "include/review.hpp"
#include "include/search_timestamp.hpp"
#include "include/searched_route.hpp"
#include "include/state.hpp"
#include "include/user.hpp"
#include "include/util.hpp"
#include "include/vars.hpp"
#include "include/visit.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>


int main() {
  RandomValueGenerator rvg{};
  std::vector<std::shared_ptr<User>> all_users{};
  std::vector<Problem> all_problems{};
  std::vector<Offer> all_offers{};
  std::vector<Request> all_requests{};
  std::vector<Review> all_reviews{};
  std::vector<SearchTimestamp> all_search_timestamps{};
  std::vector<SearchedRoute> all_searched_routes{};
  std::vector<Visit> all_visits{};

  std::vector<std::shared_ptr<User>> drivers{};
  std::vector<std::shared_ptr<User>> passengers{};

  std::vector<std::pair<int, std::string>> states{{1, "CANCELLED"},
                                                  {2, "REJECTED"},
                                                  {3, "PENDING"},
                                                  {4, "FINISHED"},
                                                  {5, "ACCEPTED"}};

  std::random_device rd;
  std::mt19937 g(rd());

  int user_count = 1000;
  int visit_count = 30 * user_count * (vars::current_year - vars::app_creation_year);
  int search_count = visit_count * 3;
  int problem_count = user_count / 50;

  std::cout << "Generate random visits\n";
  // generate random visits
  for (int i = 0; i < visit_count; ++i) {
    all_visits.push_back({});
  }

  std::cout << "Generating search statistics\n";

  // generate search statistics
  for (int i = 0; i < search_count; ++i) {
    SearchedRoute sr{};
    if (std::find(all_searched_routes.begin(), all_searched_routes.end(), sr) ==
        all_searched_routes.end()) {
      all_searched_routes.push_back(sr);
    }
    all_search_timestamps.push_back({sr.get_id()});
  }

  // generate users
  std::cout << "Generating users\n";
  for (int i = 0; i < user_count; ++i) {
    all_users.push_back(std::make_shared<User>());
  }

  // shuffle users

  std::shuffle(all_users.begin(), all_users.end(), g);
  std::cout << "Generate problems\n";
  // generate problems
  int random_number{};
  for (int i = 0; i < problem_count; ++i) {
    random_number = rvg.get_random_int(0, all_users.size() - 1);
    all_problems.push_back({all_users[random_number]->get_id(),
                            all_users[random_number]->get_created_at()});
  }

  // select drivers
  std::cout << "Selecting drivers\n";
  int number_of_drivers = all_users.size() * 0.4f;
  int number_of_passengers = all_users.size() * 0.8f;
  for (int i = 0; i < number_of_drivers; ++i) {
    drivers.push_back(all_users[i]);
  }

  // shuffle again before selecting passengers so that there isn't a complete
  // overlap with the drivers
  std::shuffle(all_users.begin(), all_users.end(), g);

  for (int i = 0; i < number_of_passengers; ++i) {
    passengers.push_back(all_users[i]);
  }

  // generate offers
  for (const auto &driver : drivers) {
    all_offers.push_back({driver->get_id(), driver->get_created_at()});
  }
  std::cout << "Handling offers\n";

  for (Offer &offer : all_offers) {

    // Cancel 2% of offers
    if (rvg.get_random_int(1, 100) <= 2) {
      offer.cancel();
      continue;
    }

    // some seats can remain empty
    int target_capacity = rvg.get_weighted_random_int(1, offer.get_free_seats(), {0.2, 0.25, 0.25, 0.3});
    while (offer.get_taken_seats() < target_capacity) {

      auto passenger = passengers[rvg.get_random_int(0, passengers.size() - 1)];
      auto passenger_date = util::string_to_date(passenger->get_created_at());
      auto offer_date = util::string_to_date(offer.get_publication_time());

      if (passenger_date < offer_date) {
        Request request{passenger->get_id(), offer.get_id()};
        all_requests.push_back(request);
        if (request.get_status() == static_cast<int>(State::ACCEPTED) ||
            request.get_status() == static_cast<int>(State::FINISHED)) {
          offer.fill_seat();
          // leave a review only if the offer is finished
          if (request.get_status() != static_cast<int>(State::ACCEPTED)) {
            all_reviews.push_back({offer.get_departure(), offer.get_id(),
                                   offer.get_driver(), passenger->get_id(), passenger->get_age()});
          }
        }
      }
    }
  }
  // print all values
  std::cout << "Writing to file started\n";
  std::ofstream outFile("output.sql");

  if (!outFile.is_open()) {
    std::cerr << "Failed to open the file for writing." << std::endl;
    return 1;
  }

  for (auto const &s : states) {
    outFile << "INSERT INTO state(id, name) VALUES(" << s.first << ", '"
            << s.second << "');\n";
  }

  for (auto const &v : all_visits) {
    outFile << v << '\n';
  }
  for (auto const &sr : all_searched_routes) {
    outFile << sr << '\n';
  }
  for (auto const &st : all_search_timestamps) {
    outFile << st << '\n';
  }

  for (auto const &u : all_users) {
    outFile << *u << '\n';
  }

  for (auto const &p : all_problems) {
    outFile << p << '\n';
  }

  for (auto const &o : all_offers) {
    outFile << o << '\n';
  }

  for (auto const &r : all_requests) {
    outFile << r << '\n';
  }
  for (auto const &r : all_reviews) {
    outFile << r << '\n';
  }

  outFile << "SELECT setval('user_id_seq', "<< user_count+1 << ");" << '\n';

  outFile.close();
}





