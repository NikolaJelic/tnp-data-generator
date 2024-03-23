#include "include/util.hpp"
#include <chrono>
#include <iostream>
#include <ostream>

int main() {
  for (int i = 0; i < 100; ++i) {
    std::cout << util::get_random_time(
        util::hour_weights) << '\n'; 
  }
}