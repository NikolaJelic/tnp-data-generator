#include "include/util.hpp"
#include <chrono>
#include <iostream>
#include <ostream>

int main() {
  for (int i = 0; i < 100; ++i) {
    std::cout << util::get_random_date(1999, 2008, {0.1, 0.4, 0.2, 0.3}) << '\n'; 
  }
}