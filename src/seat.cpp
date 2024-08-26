#include "seat.hpp"

// Constructor that takes a seat ID as a string
Seat::Seat(const std::string& id) : seatId(id), isBooked(false) {}

//Method to book a particular seat
bool Seat::book() {
    if (!isBooked) {
        isBooked = true;
        return true;
    }
    return false;
}

//Function to Return if a particular seat is available
bool Seat::isAvailable() const { return !isBooked; }

//Function to get the seatID
const std::string& Seat::getSeatId() const { return seatId; }

// Move Constructor
Seat::Seat(Seat&& other) noexcept : seatId(std::move(other.seatId)), isBooked(other.isBooked) {
    other.isBooked = false;
}

// Move Assignment Operator
Seat& Seat::operator=(Seat&& other) noexcept {
    if (this != &other) {
        seatId = std::move(other.seatId);
        isBooked = other.isBooked;
        other.isBooked = false;
    }
    return *this;
}
