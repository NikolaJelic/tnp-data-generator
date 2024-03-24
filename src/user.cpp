#include "include/user.hpp"

int User::id_counter = 0;


User::User() {

  this->id = id_counter;
  ++User::id_counter;
  this->surname = rvg.get_random_surname();
  this->gender = rvg.get_random_int(1, 10) < vars::male_probability;
  this->name = rvg.get_random_name(gender);
  this->birth_date = rvg.get_random_date(1966, 2006, vars::year_weights);
  this->city = rvg.get_random_city();
  this->phone_number = rvg.get_random_phone_number();
  this->password = rvg.get_random_password();
  this->created_at =
      rvg.get_random_date(2019, 2024, vars::account_creation_weights);
  this->email = rvg.get_random_email(this->name, this->surname);
}

std::ostream &operator<<(std::ostream &os, const User &user) {
  os << "Name: " << user.name << "\n";
  os << "Surname: " << user.surname << "\n";
  os << "Birth Date: " << user.birth_date << "\n";
  os << "City: " << user.city << "\n";
  os << "Email: " << user.email << "\n";
  os << "Password: " << user.password << "\n";
  os << "Phone Number: " << user.phone_number << "\n";
  os << "Image: " << user.image << "\n";
  os << "Is Verified: " << std::boolalpha << user.is_verified << "\n";
  os << "Created At: " << user.created_at << "\n";
  os << "Gender: " << (user.gender ? "Male" : "Female") << "\n";
  os << "Is Disabled: " << std::boolalpha << user.is_disabled << "\n";
  os << "ID: " << user.id << "\n";
  return os;
}