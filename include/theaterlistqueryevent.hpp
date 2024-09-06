#pragma once

#include "booking_manager.hpp"

class TheaterListQueryEvent : public Event {
private:
    std::string movieTitle;
    std::vector<std::string> theaterNames;

public:
    TheaterListQueryEvent(const std::string& title, const std::vector<std::string>& theaters)
        : movieTitle(title), theaterNames(theaters) {}

    const std::string& getMovieTitle() const {
        return movieTitle;
    }

    const std::vector<std::string>& getTheaterNames() const {
        return theaterNames;
    }

    std::string getType() const override {
        return "TheaterListQueryEvent";
    }
};
