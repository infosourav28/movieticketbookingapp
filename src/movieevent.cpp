#include "booking_manager.hpp"

MovieEvent::MovieEvent(const std::string& desc, const std::string& title)  : movieTitle(title), description(desc) {}
    
std::string MovieEvent::getType() const {
    return "MovieEvent";
}

std::string MovieEvent::getMovieTitle() const {
    return movieTitle;
}

std::string MovieEvent::getDescription() const {
    return description;
}