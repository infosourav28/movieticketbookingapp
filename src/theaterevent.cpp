#include "booking_manager.hpp"

TheaterEvent::TheaterEvent(const std::string& desc, const std::string& movie, const std::string& theater)
    : movieTitle(movie), theaterName(theater), description(desc) {}

// Getter methods
std::string TheaterEvent::getType() const {
    return "TheaterEvent";
}

std::string TheaterEvent::getMovieTitle() const {
    return movieTitle;
}

std::string TheaterEvent::getTheaterName() const {
    return theaterName;
}

std::string TheaterEvent::getDescription() const {
    return description;
}