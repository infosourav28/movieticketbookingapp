#ifndef BOOKINGEVENT_HPP
#define BOOKINGEVENT_HPP

#include "booking_manager.hpp"

class BookingEvent : public Event {
    std::string movieTitle;
    std::string theaterName;
    std::string seatId;
    std::string description;

public:
    BookingEvent(const std::string& desc, const std::string& movie, const std::string& theater, const std::string& seat);

    std::string getType() const override ;
    std::string getMovieTitle() const ;
    std::string getTheaterName() const ;
    std::string getSeatId() const ;
    std::string getDescription() const;
};

#endif