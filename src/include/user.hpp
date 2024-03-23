#pragma once

#include <string>
class User{
public:

private:
std::string name{};
std::string surname{};
std::string birth_date{}; // needs date conversion into appropriate psql format
std::string city{};
std::string email{};
std::string password{};
std::string phone_number{}; // format like real phone numbers
std::string image{};
bool is_verified = {false};
std::string created_at {}; // psql timestamp
bool gender {}; // male  = true,  female = false
bool is_disabled {};
int id{}; //primary key
static int id_counter; // static variable used for id autoincrement
};