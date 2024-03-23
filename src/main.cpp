#include <iostream>
#include <chrono>
#include <ostream>
#include "include/util.hpp"

int main(){
auto now = std::chrono::system_clock::now();
auto date = util::timepoint_to_date(now);   
auto timestamp = util::date_to_timepoint(date);
auto date_new = util::timepoint_to_date(timestamp);
std::cout << now << "\n" << date << "\n" << timestamp << '\n' << date_new << '\n'; 



}