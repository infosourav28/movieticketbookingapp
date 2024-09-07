#ifndef MOVIEEVENT_HPP
#define MOVIEEVENT_HPP

#include "booking_manager.hpp"

class MovieEvent : public Event {
    std::string movieTitle;
    std::string description;

public:
    MovieEvent(const std::string& desc, const std::string& title);
    
    std::string getType() const override;
    std::string getMovieTitle() const;
    std::string getDescription() const;
};

#endif