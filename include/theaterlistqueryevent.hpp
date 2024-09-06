#pragma once

#include "booking_manager.hpp"

class TheaterListQueryEvent : public Event {
private:
    std::string movieTitle;
    std::vector<std::string> theaterNames;

public:
    TheaterListQueryEvent(const std::string& title, const std::vector<std::string>& theaters);

    // Getter methods
    const std::string& getMovieTitle() const;

    const std::vector<std::string>& getTheaterNames() const;

    std::string getType() const override;
};
