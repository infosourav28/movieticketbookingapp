#ifndef UI_HPP
#define UI_HPP

#include "booking_manager.hpp"

class UI : public ObserverBase {
public:
    // Override the update method to handle different event types
    void update(Event* event) override;

private:
    // Handling MovieEvent in the UI
    void handleMovieEvent(MovieEvent* event);

    // Handling TheaterEvent in the UI
    void handleTheaterEvent(TheaterEvent* event);

    // Handling BookingEvent in the UI
    void handleBookingEvent(BookingEvent* event);

    void handleSeatQueryEvent(const SeatQueryEvent* event);
    
    void handleMovieListQueryEvent(const MovieListQueryEvent* event);

    void handleTheaterListQueryEvent(const TheaterListQueryEvent* event);
};

#endif
