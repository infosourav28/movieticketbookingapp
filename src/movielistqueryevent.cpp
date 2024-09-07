#include "booking_manager.hpp"

MovieListQueryEvent::MovieListQueryEvent(const std::vector<std::string>& titles)
        : movieTitles(titles) {}

const std::vector<std::string>& MovieListQueryEvent::getMovieTitles() const {
    return movieTitles;
}

// Implement the pure virtual function from Event
std::string MovieListQueryEvent::getType() const {
    return "MovieListQueryEvent";
}