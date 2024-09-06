#ifndef UI_HPP
#define UI_HPP

#include "booking_manager.hpp"

class UI : public ObserverBase {
public:
    // Override the update method to handle different event types
    void update(Event* event) override {
        // Identify the event type and cast appropriately
        if (event->getType() == "MovieEvent") {
            handleMovieEvent(static_cast<MovieEvent*>(event));
        } 
        else if (event->getType() == "TheaterEvent") {
            handleTheaterEvent(static_cast<TheaterEvent*>(event));
        } 
        else if (event->getType() == "BookingEvent") {
            handleBookingEvent(static_cast<BookingEvent*>(event));
        }
        else if (event->getType() == "SeatQueryEvent"){
            handleBookingEvent(static_cast<SeatQueryEvent*>(event));
        }
        else if (event->getType() == "MovieListQueryEvent"){
            handleBookingEvent(static_cast<MovieListQueryEvent*>(event));
        }
        else if (event->getType() == "TheaterListQueryEvent"){
            handleBookingEvent(static_cast<TheaterListQueryEvent*>(event));
        }

    }

private:
    // Handling MovieEvent in the UI
    void handleMovieEvent(MovieEvent* event) {
        std::cout << "UI Update: " << event->getDescription() << " - Movie: " << event->getMovieTitle() << std::endl;
        // Further UI logic (e.g., updating the movie list in the UI)
    }

    // Handling TheaterEvent in the UI
    void handleTheaterEvent(TheaterEvent* event) {
        std::cout << "UI Update: " << event->getDescription() << " - Movie: " << event->getMovieTitle() << ", Theater: " << event->getTheaterName() << std::endl;
        // Further UI logic (e.g., adding theater info for the specific movie in the UI)
    }

    // Handling BookingEvent in the UI
    void handleBookingEvent(BookingEvent* event) {
        std::cout << "UI Update: " << event->getDescription() << " - Movie: " << event->getMovieTitle() 
                  << ", Theater: " << event->getTheaterName() << ", Seat: " << event->getSeatId() << std::endl;
        // Further UI logic (e.g., marking the seat as booked in the UI)
    }

    void handleSeatQueryEvent(const SeatQueryEvent* event) {
    // Extract details from the event
    std::string movieTitle = event->getMovieTitle();
    std::string theaterName = event->getTheaterName();
    const auto& availableSeats = event->getAvailableSeats();
    size_t totalAvailableSeats = event->getTotalAvailableSeats();

    // Update the UI or log information
    std::cout << "Movie Title: " << movieTitle << std::endl;
    std::cout << "Theater Name: " << theaterName << std::endl;
    std::cout << "Total Available Seats: " << totalAvailableSeats << std::endl;

    if (availableSeats.empty()) {
        std::cout << "No seats available." << std::endl;
    } 
    else 
    {
        std::cout << "Available Seats:" << std::endl;
        for (const auto& seat : availableSeats) 
        {
            std::cout << "Seat ID: " << seat->getId() << std::endl;
        }
    }
    }
    
    void handleMovieListQueryEvent(const MovieListQueryEvent* event) {
    const auto& movieTitles = event->getMovieTitles();
    std::cout << "Currently Playing Movies:" << std::endl;
    for (const auto& title : movieTitles) {
        std::cout << title << std::endl;
    }
    }

    void handleTheaterListQueryEvent(const TheaterListQueryEvent* event) {
    if (event) {
        // Extract movie title and theater names from the event
        std::string movieTitle = event->getMovieTitle();
        const std::vector<std::string>& theaterNames = event->getTheaterNames();

        // Update the UI or perform necessary actions
        std::cout << "Theaters showing movie: " << movieTitle << std::endl;
        if (theaterNames.empty()) {
            std::cout << "No theaters found for this movie." << std::endl;
        } else {
            std::cout << "Theaters showing '" << movieTitle << "':" << std::endl;
            for (const auto& name : theaterNames) {
                std::cout << " - " << name << std::endl;
            }
        }
    }
}


};


#endif