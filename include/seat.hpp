#ifndef SEAT_HPP
#define SEAT_HPP

#include <string>

#ifdef _WIN32
    #ifdef BOOKING_EXPORTS
        #define BOOKING_API __declspec(dllexport)
    #else
        #define BOOKING_API __declspec(dllimport)
    #endif
#else
    #define BOOKING_API __attribute__((visibility("default")))
#endif

class BOOKING_API Seat {
    std::string seatId;
    bool isBooked;

public:
    //Default constructor
    Seat()=default;
    //Explicit single argument Constructor that takes a seat ID as a string
    explicit Seat(const std::string& id);

    //Function to book seat
    bool book();
    // Function to check if a seat is available
    bool isAvailable() const;

    //Function to read the seat ID
    const std::string& getSeatId() const;

    // Destructor
    ~Seat() = default;

    // Move Constructor
    Seat(Seat&& other) noexcept;
    // Move Assignment Operator
    Seat& operator=(Seat&& other) noexcept;

    // Delete copy constructor and copy assignment operator
    Seat(const Seat&) = delete;
    Seat& operator=(const Seat&) = delete;
};

#endif // SEAT_HPP
