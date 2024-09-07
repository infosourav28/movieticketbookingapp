#include "booking_manager.hpp"
#include "ui.hpp"
void setupBookingSystem() {
        BookingManager& manager = BookingManager::getInstance();

        // Add movies
        manager.addMovie(std::make_shared<Movie>("Inception", "Action", 120));
        manager.addMovie(std::make_shared<Movie>("Avatar", "Sci-Fi", 130));

        // Add theaters
        auto theater1 = std::make_shared<Theater>("IMAX");
        auto theater2 = std::make_shared<Theater>("Regal");

        manager.addTheater("Inception", theater1);
        manager.addTheater("Avatar", theater2);

}

// Wrapper Function to book a single seat for using in thread--can be used for testing
void bookSingleSeat(const std::string& movieTitle, const std::string& theaterName, const std::string& seatId) {
    BookingManager& manager = BookingManager::getInstance();
    bool result = manager.bookSeats(movieTitle, theaterName, seatId);
    std::cout << "Booking seat " << seatId << " for movie " << movieTitle << " in theater " << theaterName << ": " 
              << (result ? "Success" : "Failed") << std::endl;
}

// Wrapper Function to book multiple seats for using in thread--canbe used for testing
void bookMultipleSeats(const std::string& movieTitle, const std::string& theaterName, const std::vector<std::string>& seatIds) {
    BookingManager& manager = BookingManager::getInstance();
    bool result = manager.bookSeats(movieTitle, theaterName, seatIds);
    std::cout << "Booking seats for movie " << movieTitle << " in theater " << theaterName << ": " 
              << (result ? "Success" : "Failed") << std::endl;
}

// Wrapper Function to retrieve available seats for using in thread--can be used for testing
void getAvailableSeats(const std::string& movieTitle, const std::string& theaterName) {
    BookingManager& manager = BookingManager::getInstance();
    auto seats = manager.getAvailableSeats(movieTitle, theaterName);
    std::cout << "Available seats for movie " << movieTitle << " in theater " << theaterName << ": " 
              << seats.size() << std::endl;
    for (const auto& seat : seats) {
        std::cout << seat->getSeatId() << "  ";
    }
    std::cout<<std::endl;
}

int main() {
    // Create booking manager
    BookingManager& manager = BookingManager::getInstance();;

    // Create some movies with genre and duration
    auto movie1 = std::make_shared<Movie>("Fast & Furious", "Action", 120);
    auto movie2 = std::make_shared<Movie>("The Hangover", "Comedy", 100);
    auto movie3 = std::make_shared<Movie>("Evil Dead Rise", "Horror", 150);
    manager.addMovie(movie1);
    manager.addMovie(movie2);
    manager.addMovie(movie3);

    // Create theaters
    auto theater1 = std::make_shared<Theater>("Theater1:BIGCINEMA");
    auto theater2 = std::make_shared<Theater>("Theater2:CINEMAXX");
    auto theater_PVR = std::make_shared<Theater>("Theater_PVR");
    manager.addTheater(movie1->getTitle(), theater1);
    manager.addTheater(movie2->getTitle(), theater2);

    //manager.addTheater(movie3->getTitle(), theater2);

    manager.addTheater(movie1->getTitle(), theater_PVR);
    manager.addTheater(movie2->getTitle(), theater_PVR);
    manager.addTheater(movie3->getTitle(), theater_PVR);

     // View and display all playing movies
    auto playingMovies = manager.getAllPlayingMovies();
    std::cout << "\nCurrently playing movies:" << std::endl;
    for (const auto& title : playingMovies) {
        std::cout << "- " << title << std::endl;
    }

std::cout<<"-------------------------------------------------"<<std::endl;
    // View and display all theaters showing "Fast & Furious"
    auto theatersForMovie2 = manager.getTheatersShowingMovie("Fast & Furious");
    std::cout << "\nAll the Theaters showing 'Fast & Furious':" << std::endl;
    for (const auto& theaterName : theatersForMovie2) {
        std::cout << "- " << theaterName << std::endl;
    }

std::cout<<"-------------------------------------------------"<<std::endl;
    // View and display all theaters showing "The Hangover"
    auto theatersForMovie3 = manager.getTheatersShowingMovie("The Hangover");
    std::cout << "\nAll The Theaters showing 'The Hangover':" << std::endl;
    for (const auto& theaterName : theatersForMovie3) {
        std::cout << "- " << theaterName << std::endl;
    }

std::cout<<"-------------------------------------------------"<<std::endl;
    // View and display all theaters showing "Evil Dead Rise"
    auto theatersForMovie1 = manager.getTheatersShowingMovie("Evil Dead Rise");
    std::cout << "\nAll the Theaters showing 'Evil Dead Rise':" << std::endl;
    for (const auto& theaterName : theatersForMovie1) {
        std::cout << "- " << theaterName << std::endl;
    }
std::cout<<"-------------------------------------------------"<<std::endl;

    // Book some seat
    std::cout << "\nBooking seat a1 in Theater1:BIGCINEMA for Fast & Furious: "
              << (manager.bookSeats("Fast & Furious", "Theater1:BIGCINEMA", "a1") ? "Success" : "Failed")
              << std::endl;
        // Book some seat
    std::cout << "\nBooking seat a2 in Theater_PVR for Fast & Furious: "
              << (manager.bookSeats("Fast & Furious", "Theater_PVR", "a2") ? "Success" : "Failed")
              << std::endl;
        // Book some seat
    std::cout << "\nBooking seat a5 in Theater_PVR for Evil Dead Rise: "
              << (manager.bookSeats("Evil Dead Rise", "Theater_PVR", "a5") ? "Success" : "Failed")
              << std::endl;

std::cout<<"---------------------------------------------------------------------------"<<std::endl;
    // Attempt to book multiple seats
    std::cout << "\nAttempt to book multiple seats a1, a3, a4 of The Hangover in Theater_PVR: "<<std::endl;
    std::vector<std::string> seatsToBook = {"a1", "a3", "a4"};
    std::cout<< (manager.bookSeats("The Hangover", "Theater_PVR", seatsToBook) ? "Success" : "Failed") << std::endl;

std::cout<<"---------------------------------------------------------------------------------"<<std::endl;
    
    // View available seats
    std::cout << "\n\nAvailable seats in Theater1:BIGCINEMA for Fast & Furious:" << std::endl;
    auto availableSeats = manager.getAvailableSeats("Fast & Furious", "Theater1:BIGCINEMA");
    for (const auto& seat : availableSeats) {
        std::cout << seat->getSeatId() << "  ";
    }

    // View available seats
    std::cout << "\n\nAvailable seats in Theater_PVR for Fast & Furious:" << std::endl;
    auto availableSeatspvr = manager.getAvailableSeats("Fast & Furious", "Theater_PVR");
    for (const auto& seat : availableSeatspvr) {
        std::cout << seat->getSeatId() << "  ";
    }

    std::cout << "\n\nAvailable seats in Theater2:CINEMAXX for Evil Dead Rise:" << std::endl;
    auto availableSeats2 = manager.getAvailableSeats("Evil Dead Rise", "Theater2:CINEMAXX");
    for (const auto& seat : availableSeats2) {
        std::cout << seat->getSeatId() << "  ";
    }

    std::cout << "\n\nAvailable seats in Theater2:CINEMAXX for The Hangover:" << std::endl;
    auto availableSeats3 = manager.getAvailableSeats("The Hangover", "Theater2:CINEMAXX");
    for (const auto& seat : availableSeats3) {
        std::cout << seat->getSeatId() << "  ";
    }

    // View available seats
    std::cout << "\n\nAvailable seats in Theater_PVR for Fast & Furious:" << std::endl;
    auto availableSeatspvr2 = manager.getAvailableSeats("Fast & Furious", "Theater_PVR");
    for (const auto& seat : availableSeatspvr2) {
        std::cout << seat->getSeatId() << "  ";
    }

    std::cout << "\n\nAvailable seats in Theater_PVR for The Hangover:" << std::endl;
    auto availableSeatspvr3 = manager.getAvailableSeats("The Hangover", "Theater_PVR");
    for (const auto& seat : availableSeatspvr3) {
        std::cout << seat->getSeatId() << "  ";
    }

std::cout<<"\n----------------------------------------------------------------------------"<<std::endl;
    
    std::cout << "\n\nAGAIN Booking seat a5 in Theater_PVR for Evil Dead Rise: "
            << (manager.bookSeats("Evil Dead Rise", "Theater_PVR", "a5") ? "Success" : "Failed")
            << std::endl;

std::cout<<"\n----------------------------------------------------------------------------"<<std::endl;
   
    // View available seats
    std::cout << "\n\nAvailable seats in Theater_PVR for Evil Dead Rise:" << std::endl;
    auto availableSeatspvr_evildead = manager.getAvailableSeats("Evil Dead Rise", "Theater_PVR");
    for (const auto& seat : availableSeatspvr_evildead) {
        std::cout << seat->getSeatId() << "  ";
    }

std::cout<<"\n-------------------------------------------------------------------------"<<std::endl;
    
    std::cout << "\n\nBooked Seats for The Hangover in Theater_PVR:" << std::endl;
    auto bookedSeats = manager.getBookedSeats("The Hangover", "Theater_PVR");
    for (const auto& seat : bookedSeats) {
        std::cout << "Booked Seat ID: " << seat->getSeatId() << std::endl;
    }

std::cout<<"\n---------------------------------------------------------------------------"<<std::endl;
    
    setupBookingSystem();
    // Define the number of threads
    const int numThreads = 10;

    // Create threads for booking single seats
    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(bookSingleSeat, "Inception", "IMAX", "a" + std::to_string(i % 10 + 1));
    }

    // Join threads
    for (auto& thread : threads) {
        thread.join();
    }

std::cout<<"\n-----------------------------------------------------------------"<<std::endl;
    
    // Create threads for booking multiple seats
    std::vector<std::string> seatIds = {"a1", "a2", "a3"};
    threads.clear();
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(bookMultipleSeats, "Avatar", "Regal", seatIds);
    }

    // Join threads
    for (auto& thread : threads) {
        thread.join();
    }

std::cout<<"-------------------------------------------------------------------"<<std::endl;
    
    // Retrieve available seats
    getAvailableSeats("Inception", "IMAX");
    getAvailableSeats("Avatar", "Regal");

std::cout<<"\n-------------------------------------------------------------------"<<std::endl;

// Create a UI object and register it as an observer
    std::shared_ptr<UI> ui = std::make_shared<UI>();
    manager.registerObserver(ui);

    // Perform operations that will trigger events
    std::shared_ptr<Movie> newMovie = std::make_shared<Movie>("KILLER","Action", 140);
    manager.addMovie(newMovie);
std::cout<<"\n-------------------------------------------------------------------"<<std::endl;

    std::shared_ptr<Theater> newTheater = std::make_shared<Theater>("IMAX");
    manager.addTheater("KILLER", newTheater);

    std::shared_ptr<Theater> newTheater2 = std::make_shared<Theater>("MOVIEONE");
    manager.addTheater("KILLER", newTheater2);

std::cout<<"\n-------------------------------------------------------------------"<<std::endl;

    // Book a seat
    manager.bookSeats("KILLER", "IMAX", "a1");
    manager.bookSeats("KILLER", "IMAX", "a5");
    manager.bookSeats("KILLER", "IMAX", "a7");

    manager.bookSeats("KILLER", "IMAX", {"a8","a9","a10"});
std::cout<<"\n-------------------------------------------------------------------"<<std::endl;

    manager.getAllPlayingMovies();
std::cout<<"\n-------------------------------------------------------------------"<<std::endl;

    manager.getAvailableSeats("KILLER", "IMAX");
std::cout<<"\n-------------------------------------------------------------------"<<std::endl;
    manager.getTheatersShowingMovie("KILLER");
    manager.getTheatersShowingMovie("Inception");
    return 0;
}
