#pragma once

#include <string>
class Offer{
    public:

    private:
    std::string start{}; // location
    std::string end{}; // location
    float price{}; // 2 decimal places
    int seats{};
    int taken_seats{};
    std::string vehicle{};
    std::string description{};
    std::string publication_date_time{}; //psql timestamp
    std::string departure_date_time{}; // psql timestamp
    bool is_canceled{false};
    int user_id{}; // foreign key
    int id{}; //primary key
    static int id_counter; // static variable used for id autoincrement
};