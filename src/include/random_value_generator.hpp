#pragma once
#include <iomanip>
#include <random>
#include <sstream>
#include <string>
#include <vector>

class RandomValueGenerator {
public:
  RandomValueGenerator() : gen(std::random_device()()) {}

  std::string get_random_time(std::vector<double> weights);

  std::string get_random_date(int start_year, int end_year,
                              std::vector<double> weights);

  std::vector<double> distribute_weights(std::vector<double> weights,
                                         int result_count);
  int get_random_int(int min, int max);
  std::string get_random_name();
  std::string get_random_surname();
  std::string get_random_email(std::string const &name,
                               std::string const &surname);
  std::string get_random_password();
private:
  std::mt19937 gen;

const std::string alphanum = "qwertyuiopasdfghjklzxcvbnm,.!1234567890QWERTYUIOPLKJHGFDSAZXCVBNM";
  const std::vector<double> hour_weights = {
      0.05, 0.04, 0.02, 0.02, 0.01, 0.01, 0,    0.03, 0.03,
      0.04, 0.04, 0.06, 0.06, 0.07, 0.06, 0.04, 0.06, 0.03,
      0.04, 0.05, 0.06, 0.05, 0.04, 0.04, 0.05};
  const std::vector<std::string> names = {
      "Aleksandar", "Ana",        "Bojan",      "Jovana",     "Milan",
      "Marija",     "Stefan",     "Nikola",     "Ivana",      "Marko",
      "Dusan",      "Svetlana",   "Petar",      "Dragana",    "Nenad",
      "Milica",     "Vladimir",   "Jelena",     "Dejan",      "Sofija",
      "Viktor",     "Tijana",     "Branislav",  "Ana",        "Filip",
      "Andjela",    "Katarina",   "Darko",      "Nina",       "Goran",
      "Maja",       "Zoran",      "Jasmina",    "Davor",      "Sanja",
      "Vladan",     "Tamara",     "Nemanja",    "Dijana",     "Boris",
      "Jovanka",    "Luka",       "Sara",       "Aleksandra", "Milena",
      "Predrag",    "Dragana",    "Vuk",        "Danica",     "Vesna",
      "Bojana",     "Gordana",    "Ljubica",    "Marina",     "Zorica",
      "Goran",      "Natasa",     "Mirjana",    "Gordana",    "Dusan",
      "Milka",      "Branka",     "Anastasija", "Jovanka",    "Gordana",
      "Miroslav",   "Jelena",     "Nikolina",   "Milan",      "Milan",
      "Jovan",      "Biljana",    "Zoran",      "Jovanka",    "Dragan",
      "Svetlana",   "Aleksandar", "Biljana",    "Milica",     "Nikolaj",
      "Vesna",      "Ivan",       "Jelena",     "Marko",      "Jovana",
      "Petar",      "Svetlana",   "Stefan",     "Ana",        "Dusan",
      "Sanja",      "Vladimir",   "Dragana",    "Nenad",      "Jovana",
      "Viktor",     "Nina",       "Branislav",  "Katarina",   "Igor",
      "Darko",      "Maja",       "Jasmina",    "Zoran",      "Tijana",
      "Davor",      "Milica",     "Vladan",     "Sofija",     "Nemanja",
      "Jelena",     "Boris",      "Ana",        "Luka",       "Sara",
      "Aleksandra", "Andjela",    "Vuk",        "Nina",       "Vesna",
      "Milica",     "Gordana",    "Sanja",      "Marina",     "Bojana",
      "Zorica",     "Ljubica",    "Dusan",      "Anastasija", "Branka",
      "Jovanka",    "Mirjana",    "Gordana",    "Miroslav",   "Jelena",
      "Nikolina",   "Milan",      "Natasa",     "Jovan",      "Milka",
      "Zoran",      "Biljana",    "Dragan",     "Jovanka",    "Aleksandar",
      "Svetlana",   "Milica",     "Nikola",     "Vesna",      "Ivan",
      "Jelena",     "Marko",      "Jovana",     "Petar",      "Svetlana",
      "Stefan",     "Ana",        "Dusan",      "Sanja",      "Vladimir",
      "Dragana",    "Jovana",     "Nina",       "Branislav",  "Katarina",
      "Igor",       "Tamara",     "Darko",      "Maja",       "Jasmina",
      "Zoran",      "Tijana",     "Davor",      "Milica",     "Vladan",
      "Sofija",     "Nemanja",    "Jelena",     "Boris",      "Ana",
      "Luka",       "Sara",       "Aleksandra", "Andjela",    "Vuk",
      "Nina",       "Vesna",      "Gordana",    "Sanja",      "Marina",
      "Bojana",     "Zorica",     "Ljubica",    "Dusan",      "Anastasija",
      "Branka",     "Jovanka",    "Mirjana",    "Gordana",    "Miroslav",
      "Jelena",     "Nikolina",   "Milan",      "Natasa",     "Jovan",
      "Milka",      "Zoran",      "Biljana",    "Dragan",     "Jovanka",
      "Aleksandar", "Svetlana",   "Milica",     "Nikola",     "Vesna",
      "Ivan",       "Jelena",     "Marko",      "Jovana",     "Petar",
      "Svetlana",   "Stefan",     "Ana",        "Dusan",      "Sanja",
      "Vladimir",   "Dragana",    "Jovana",     "Viktor",     "Nina",
      "Branislav",  "Katarina",   "Igor",       "Tamara",     "Darko",
      "Maja",       "Goran",      "Jasmina",    "Zoran",      "Tijana",
      "Davor",      "Vladan",     "Sofija",     "Nemanja",    "Jelena",
      "Boris",      "Ana",        "Luka",       "Sara",       "Aleksandra",
      "Andjela",    "Vuk",        "Nina",       "Vesna",      "Milica",
      "Gordana",    "Sanja",      "Marina",     "Bojana",     "Zorica",
      "Ljubica",    "Dusan",      "Anastasija", "Branka",     "Jovanka",
      "Mirjana",    "Gordana",    "Miroslav",   "Jelena",     "Nikolina",
      "Milan",      "Natasa",     "Jovan",      "Milka",      "Zoran",
      "Biljana",    "Dragan",     "Jovanka",    "Aleksandar", "Svetlana",
      "Milica",     "Nikola",     "Vesna",      "Ivan",       "Jelena",
      "Marko",      "Jovana",     "Petar",      "Svetlana",   "Stefan",
      "Ana",        "Dusan",      "Sanja",      "Vladimir",   "Dragana",
      "Nenad",      "Jovana",     "Viktor",     "Nina",       "Branislav",
      "Katarina",   "Igor",       "Tamara",     "Darko"};

  const std::vector<std::string> surnames = {
      "Popovic",      "Ivanovic",     "Nikolic",      "Jovanovic",
      "Markovic",     "Petrovic",     "Milosevic",    "Stojanovic",
      "Vukovic",      "Stevanovic",   "Radovanovic",  "Milanovic",
      "Kostic",       "Kovacevic",    "Simic",        "Nedic",
      "Zivkovic",     "Djordjevic",   "Pavlovic",     "Stankovic",
      "Mitrovic",     "Ristic",       "Vujic",        "Dimitrijevic",
      "Kovacevic",    "Blazic",       "Ilic",         "Lukic",
      "Maksimovic",   "Stefanovic",   "Jankovic",     "Maric",
      "Veselinovic",  "Pavlovic",     "Djokovic",     "Gajic",
      "Nedic",        "Nikolic",      "Milosevic",    "Kovacevic",
      "Simic",        "Milanovic",    "Stojanovic",   "Markovic",
      "Jovanovic",    "Ivanovic",     "Petrovic",     "Stevanovic",
      "Vukovic",      "Popovic",      "Radovanovic",  "Kostic",
      "Djordjevic",   "Ristic",       "Zivkovic",     "Mitrovic",
      "Stankovic",    "Vujic",        "Pavlovic",     "Kovacevic",
      "Dimitrijevic", "Blazic",       "Lukic",        "Ilic",
      "Maksimovic",   "Stefanovic",   "Maric",        "Jankovic",
      "Gajic",        "Veselinovic",  "Djokovic",     "Nikolic",
      "Jovanovic",    "Petrovic",     "Popovic",      "Milosevic",
      "Stevanovic",   "Markovic",     "Ivanovic",     "Kovacevic",
      "Stojanovic",   "Simic",        "Vukovic",      "Radovanovic",
      "Pavlovic",     "Kostic",       "Djordjevic",   "Milanovic",
      "Stankovic",    "Mitrovic",     "Ristic",       "Zivkovic",
      "Vujic",        "Pavlovic",     "Kovacevic",    "Blazic",
      "Djokovic",     "Maksimovic",   "Ilic",         "Stefanovic",
      "Lukic",        "Maric",        "Gajic",        "Jankovic",
      "Dimitrijevic", "Nikolic",      "Veselinovic",  "Nedic",
      "Milanovic",    "Stojanovic",   "Stankovic",    "Vukovic",
      "Djordjevic",   "Simic",        "Markovic",     "Radovanovic",
      "Jovanovic",    "Ivanovic",     "Petrovic",     "Popovic",
      "Milosevic",    "Stevanovic",   "Kovacevic",    "Kostic",
      "Pavlovic",     "Ristic",       "Mitrovic",     "Zivkovic",
      "Djokovic",     "Blazic",       "Vujic",        "Kovacevic",
      "Stefanovic",   "Lukic",        "Djordjevic",   "Maksimovic",
      "Ilic",         "Maric",        "Gajic",        "Nikolic",
      "Jankovic",     "Veselinovic",  "Nedic",        "Simic",
      "Milanovic",    "Jovanovic",    "Stojanovic",   "Popovic",
      "Milosevic",    "Stevanovic",   "Markovic",     "Ivanovic",
      "Petrovic",     "Kovacevic",    "Stankovic",    "Kostic",
      "Mitrovic",     "Pavlovic",     "Zivkovic",     "Ristic",
      "Djokovic",     "Blazic",       "Vujic",        "Vukovic",
      "Lukic",        "Dimitrijevic", "Ilic",         "Kovacevic",
      "Maksimovic",   "Stefanovic",   "Gajic",        "Jankovic",
      "Maric",        "Nikolic",      "Veselinovic",  "Nedic",
      "Djordjevic",   "Simic",        "Jovanovic",    "Stojanovic",
      "Milanovic",    "Popovic",      "Stevanovic",   "Markovic",
      "Ivanovic",     "Petrovic",     "Kovacevic",    "Stankovic",
      "Kostic",       "Mitrovic",     "Pavlovic",     "Zivkovic",
      "Ristic",       "Djokovic",     "Blazic",       "Vujic",
      "Vukovic",      "Lukic",        "Dimitrijevic", "Ilic",
      "Kovacevic",    "Maksimovic",   "Stefanovic",   "Gajic",
      "Jankovic",     "Maric",        "Nikolic",      "Veselinovic",
      "Nedic",        "Djordjevic",   "Simic",
  };
};