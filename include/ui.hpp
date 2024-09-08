#ifndef UI_HPP
#define UI_HPP

#include "booking_manager.hpp"

#ifdef _WIN32
    #ifdef BOOKING_EXPORTS
        #define BOOKING_API __declspec(dllexport)
    #else
        #define BOOKING_API 
    #endif
#else
    #define BOOKING_API __attribute__((visibility("default")))
#endif

class BOOKING_API UI : public ObserverBase {
public:
    // Override the update method to handle different event types
    void update(Event* event) override;
	~UI();

private:
    // Handling MovieEvent in the UI
    void handleMovieEvent(MovieEvent* event);

    // Handling TheaterEvent in the UI
    void handleTheaterEvent(TheaterEvent* event);

    // Handling BookingEvent in the UI
    void handleBookingEvent(BookingEvent* event);

    // Handling SeatQueryEvent in the UI
    void handleSeatQueryEvent(const SeatQueryEvent* event);

    // Handling MovieListQueryEvent in the UI
    void handleMovieListQueryEvent(const MovieListQueryEvent* event);

    // Handling TheaterListQueryEvent in the UI
    void handleTheaterListQueryEvent(const TheaterListQueryEvent* event);
};

#endif
