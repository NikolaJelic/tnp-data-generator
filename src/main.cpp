#include "include/random_value_generator.hpp"
#include "include/util.hpp"
#include <iostream>
#include <ostream>

int main() { RandomValueGenerator rvg{};
std::cout <<rvg.get_random_password() << 'n';
 }