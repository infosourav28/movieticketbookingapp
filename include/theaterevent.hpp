#ifndef THEATEREVENT_HPP
#define THEATEREVENT_HPP

#include "booking_manager.hpp"

class TheaterEvent : public Event {
    std::string movieTitle;
    std::string theaterName;
    std::string description;

public:
    TheaterEvent(const std::string& desc, const std::string& movie, const std::string& theater)
        : movieTitle(movie), theaterName(theater), description(desc) {}

    std::string getType() const override { return "TheaterEvent"; }
    std::string getMovieTitle() const { return movieTitle; }
    std::string getTheaterName() const { return theaterName; }
    std::string getDescription() const { return description; }
};

#endif