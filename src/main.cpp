#include "include/random_value_generator.hpp"
#include "include/user.hpp"
#include "include/util.hpp"
#include <iostream>
#include <ostream>


int main() {
  RandomValueGenerator rvg{};
  for (int i = 0; i < 20; ++i) {
    User u{};
    std::cout << u << '\n';
  }
}