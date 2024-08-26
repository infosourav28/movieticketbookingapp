#include "theater.hpp"

// Constructor
Theater::Theater(const std::string& name) : name(std::move(name)) {}

// Function to read/get the theater Name
const std::string& Theater::getName() const {
    return name;
}

//Updated function for initializing seats for each movie
void Theater::initializeSeatsForMovie(const std::string& movieTitle) {
    std::vector<std::shared_ptr<Seat>> seats;
    for (int i = 1; i <= 20; ++i) {
        seats.emplace_back(std::make_shared<Seat>("a"+ std::to_string(i)));  // Seat IDs will be 1 to 20
    }
    movieSeats[movieTitle] = std::move(seats);  // Associate seats with the movie
}

//Updated function for getting available seats for each movie
std::vector<std::shared_ptr<Seat>> Theater::getAvailableSeats(const std::string& movieTitle) const {
    std::vector<std::shared_ptr<Seat>> availableSeats;
    auto it = movieSeats.find(movieTitle);
    if (it != movieSeats.end()) {
        for (const auto& seat : it->second) {
            if (seat->isAvailable()) {
                availableSeats.push_back(seat);
            }
        }
    }
    return availableSeats;
}

//Updated function for bookSeat for each movie
bool Theater::bookSeat(const std::string& movieTitle, const std::string& seatId) {
    auto it = movieSeats.find(movieTitle);
    if (it != movieSeats.end()) {
        for (const auto& seat : it->second) {
            if (seat->getSeatId() == seatId && seat->isAvailable()) {
                seat->book();
                return true;
            }
        }
    }
    return false; // Seat not found or already booked
}

//New function for gettingbooked seats
std::vector<std::shared_ptr<Seat>> Theater::getBookedSeats(const std::string& movieTitle) const {
    std::vector<std::shared_ptr<Seat>> bookedSeats;
    auto it = movieSeats.find(movieTitle);
    if (it != movieSeats.end()) {
        for (const auto& seat : it->second) {
            if (!seat->isAvailable()) {
                bookedSeats.push_back(seat);
            }
        }
    }
    return bookedSeats;
}