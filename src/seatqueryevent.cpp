#include "booking_manager.hpp"

SeatQueryEvent::SeatQueryEvent(const std::string& desc, const std::string& movie, const std::string& theater,
                   const std::vector<std::shared_ptr<Seat>>& seats, size_t totalSeats)
        : description(desc), movieTitle(movie), theaterName(theater), availableSeats(seats), totalAvailableSeats(totalSeats) {}

std::string SeatQueryEvent::getDescription() const {
    return description + ": Movie: " + movieTitle + ", Theater: " + theaterName + 
            ", Total Available Seats: " + std::to_string(totalAvailableSeats);
}

const std::vector<std::shared_ptr<Seat>>& SeatQueryEvent::getAvailableSeats() const {
    return availableSeats;
}

size_t SeatQueryEvent::getTotalAvailableSeats() const {
    return totalAvailableSeats;
}

std::string SeatQueryEvent::getType() const {
    return "SeatQueryEvent"; 
}

std::string SeatQueryEvent::getMovieTitle() const {
    return movieTitle;
}

std::string SeatQueryEvent::getTheaterName() const {
    return theaterName;
}
