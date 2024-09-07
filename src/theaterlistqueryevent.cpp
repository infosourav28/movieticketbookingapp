#include "booking_manager.hpp"

TheaterListQueryEvent::TheaterListQueryEvent(const std::string& title, const std::vector<std::string>& theaters)
    : movieTitle(title), theaterNames(theaters) {}

// Getter methods
const std::string& TheaterListQueryEvent::getMovieTitle() const {
    return movieTitle;
}

const std::vector<std::string>& TheaterListQueryEvent::getTheaterNames() const {
    return theaterNames;
}

std::string TheaterListQueryEvent::getType() const {
    return "TheaterListQueryEvent";
}