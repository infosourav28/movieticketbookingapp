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
                   const std::vector<std::shared_ptr<Seat>>& seats, size_t totalSeats);

    // Getter methods
    std::string getDescription() const;

    const std::vector<std::shared_ptr<Seat>>& getAvailableSeats() const;

    size_t getTotalAvailableSeats() const ;

    std::string getType() const override;

    std::string getMovieTitle() const;
    
    std::string getTheaterName() const;
};

#endif // SEAT_QUERY_EVENT_HPP
