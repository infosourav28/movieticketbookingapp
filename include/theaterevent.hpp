#ifndef THEATEREVENT_HPP
#define THEATEREVENT_HPP

#include "booking_manager.hpp"

class TheaterEvent : public Event {
    std::string movieTitle;
    std::string theaterName;
    std::string description;

public:
    TheaterEvent(const std::string& desc, const std::string& movie, const std::string& theater);

    std::string getType() const override ;
    std::string getMovieTitle() const ;
    std::string getTheaterName() const ;
    std::string getDescription() const ;
};

#endif