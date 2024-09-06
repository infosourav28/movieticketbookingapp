#ifndef MOVIELISTQUERYEVENT_HPP
#define MOVIELISTQUERYEVENT_HPP

#include "booking_manager.hpp"

class MovieListQueryEvent : public Event {
private:
    std::vector<std::string> movieTitles;

public:
    MovieListQueryEvent(const std::vector<std::string>& titles)
        : movieTitles(titles) {}

    const std::vector<std::string>& getMovieTitles() const {
        return movieTitles;
    }

    // Implement the pure virtual function from Event
    std::string getType() const override {
        return "MovieListQueryEvent";
    }
};

#endif
