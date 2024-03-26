#include "include/user.hpp"

int User::id_counter = 0;

User::User() {

  this->id = User::id_counter++;
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
  this->image = gender ? rvg.get_image_male() : rvg.get_image_female();
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    std::ostringstream oss;
    oss << "INSERT INTO app_user (id, name, surname, birth_date, city, email, password, phone_number, image, is_verified, created_at, gender, is_disabled) VALUES ("
        << user.id << ", '" << user.name << "', '" << user.surname << "', '" << user.birth_date << "', '"
        << user.city << "', '" << user.email << "', '" << user.password << "', '" << user.phone_number << "', '"
        << user.image << "', " << user.is_verified << ", '" << user.created_at << "', " << user.gender << ", "
        << user.is_disabled << ");";
    
    os << oss.str();
    return os;
}