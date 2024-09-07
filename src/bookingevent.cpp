#include "booking_manager.hpp"

BookingEvent::BookingEvent(const std::string& desc, const std::string& movie, const std::string& theater, const std::string& seat)
        : movieTitle(movie), theaterName(theater), seatId(seat), description(desc) {}

std::string BookingEvent::getType() const  { 
    return "BookingEvent";
}

std::string BookingEvent::getMovieTitle() const {
    return movieTitle;
}

std::string BookingEvent::getTheaterName() const {
    return theaterName;
}

std::string BookingEvent::getSeatId() const { 
    return seatId;
}

std::string BookingEvent::getDescription() const {
    return description;
}