#ifndef BOOKING_MANAGER_HPP
#define BOOKING_MANAGER_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <mutex> 
#include <algorithm>
#include <iostream>
#include <thread>
#include "theater.hpp"
#include "movie.hpp"
//This class & its functions are exposed to the other application for eg: main.cpp
//It is purposefully made as singleton so that Only one instance of BookingManager can be present throughout the Program lifecycle
class BookingManager {
public:
    // Delete copy constructor and copy assignment operator
    BookingManager(const BookingManager&) = delete;
    BookingManager& operator=(const BookingManager&) = delete;

    // Public static method to access the singleton instance
    static BookingManager& getInstance();

    // Add a movie to the manager
    void addMovie(std::shared_ptr<Movie> movie);

    // Add a theater for a specific movie
    void addTheater(const std::string& movieTitle, std::shared_ptr<Theater> theater);

    // Book a seat for a specific movie and theater
    bool bookSeats(const std::string& movieTitle, const std::string& theaterName, const std::string& seatId);

    //Overloaded Function for Booking multiple seats for a specific movie and theater
    bool bookSeats(const std::string& movieTitle, const std::string& theaterName, const std::vector<std::string>& seatIds);

    // Get available seats for a specific movie and theater
    std::vector<std::shared_ptr<Seat>> getAvailableSeats(const std::string& movieTitle, const std::string& theaterName) const;
    
    // Method to return all the playing movies
    std::vector<std::string> getAllPlayingMovies() const;
    
    // Method to get the names of all theaters showing a particular movie
    std::vector<std::string> getTheatersShowingMovie(const std::string& movieTitle) const;

    // Function to get booked seats for a specific movie in a specific theater
    std::vector<std::shared_ptr<Seat>> getBookedSeats(const std::string& movieTitle, const std::string& theaterName) const;
    
private:
    // Private constructor to prevent instantiation
    BookingManager() = default;

    //Data Members
    std::unordered_map<std::string, std::shared_ptr<Movie>> movies; //Maps movie title to shared pointer of Movie Object
    std::unordered_map<std::string, std::vector<std::shared_ptr<Theater>>> theaters;//Maps movie titles to Theaters(SHared pointers)
    mutable std::mutex mutex; // Mutex for thread safety
};

#endif // BOOKING_MANAGER_HPP
