#ifndef SEATQUERYEVENT_HPP
#define SEATQUERYEVENT_HPP

#include "booking_manager.hpp"

class SeatQueryEvent : public Event {
private:
    std::string description;
    std::string movieTitle;
    std::string theaterName;
    std::vector<std::shared_ptr<Seat>> availableSeats;
    size_t totalAvailableSeats;

public:
    SeatQueryEvent(const std::string& desc, const std::string& movie, const std::string& theater,
                   const std::vector<std::shared_ptr<Seat>>& seats, size_t totalSeats)
        : description(desc), movieTitle(movie), theaterName(theater), availableSeats(seats), totalAvailableSeats(totalSeats) {}

    std::string getDescription() const {
        return description + ": Movie: " + movieTitle + ", Theater: " + theaterName + 
               ", Total Available Seats: " + std::to_string(totalAvailableSeats);
    }

    const std::vector<std::shared_ptr<Seat>>& getAvailableSeats() const {
        return availableSeats;
    }

    size_t getTotalAvailableSeats() const {
        return totalAvailableSeats;
    }

    std::string getType() const override { return "SeatQueryEvent"; }
};

#endif // SEAT_QUERY_EVENT_HPP
