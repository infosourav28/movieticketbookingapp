#ifndef THEATER_HPP
#define THEATER_HPP

#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include "seat.hpp"

#ifdef _WIN32
    #ifdef BOOKING_EXPORTS
        #define BOOKING_API __declspec(dllexport)
    #else
        #define BOOKING_API 
    #endif
#else
    #define BOOKING_API __attribute__((visibility("default")))
#endif

class BOOKING_API Theater {
    std::string name;
    std::unordered_map<std::string, std::vector<std::shared_ptr<Seat>>> movieSeats; // Maps movie titles to seats


public:
    Theater()=default;
    explicit Theater(const std::string& name);

     // Initialize seats for a specific movie
    void initializeSeatsForMovie(const std::string& movieTitle);

    // Get Theater Name
    const std::string& getName() const;

    // Get available seats for a specific movie
    std::vector<std::shared_ptr<Seat>> getAvailableSeats(const std::string& movieTitle) const;

    // Book a seat for a specific movie
    bool bookSeat(const std::string& movieTitle, const std::string& seatId);

    // Get booked seats for a specific movie
    std::vector<std::shared_ptr<Seat>> getBookedSeats(const std::string& movieTitle) const;

    // Destructor
    ~Theater() = default;

    // Move Constructor marking as default
    Theater(Theater&& other) noexcept = default;

    // Move Assignment Operator marking as default
    Theater& operator=(Theater&& other) noexcept = default;

    // Delete copy constructor and copy assignment operator
    Theater(const Theater&) = delete;
    Theater& operator=(const Theater&) = delete;
};

#endif // THEATER_HPP
