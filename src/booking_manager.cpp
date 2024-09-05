#include "booking_manager.hpp"

// Implementation of Meyers Singleton
BookingManager& BookingManager::getInstance() {
    static BookingManager instance;
    return instance;
}
// Add a movie to the booking manager
void BookingManager::addMovie(std::shared_ptr<Movie> movie) {
    std::lock_guard<std::mutex> lock(mutex);
    movies.insert(std::make_pair(movie->getTitle(),movie));
}

// Add a theater for a specific movie
void BookingManager::addTheater(const std::string& movieTitle, std::shared_ptr<Theater> theater) {
    std::lock_guard<std::mutex> lock(mutex);
    // Initialize seats for this movie in the theater if the movie exists in the application
    if(movies.find(movieTitle) != movies.end()){
        auto& theaterlist = theaters[movieTitle];
        //Check if the theater(passed as argument) already showing the movie
        auto it = std::find_if(theaterlist.begin(),theaterlist.end(),
                                [&theater](const std::shared_ptr<Theater>& existingTheater){
                                    return existingTheater->getName() == theater->getName();
                                });
        if(it == theaterlist.end()) //Check, if the movie not running in the theater, then initialize seats
        {
            theater->initializeSeatsForMovie(movieTitle);
            theaters[movieTitle].emplace_back(theater);
        }
        else
        {
            std::cout<<"This movie: "<<movieTitle<<" is already showing in Theater: "<<theater->getName()<<std::endl;
        }	
	    
    }
    else{
        std::cout<<"\nSORRY :( -Movie: '"<<movieTitle<<"' NOT Available in the system: Please Add it first:"<<std::endl;
        throw std::runtime_error("Unfortunately...Movie NOT added in the back end, PLEASE ADD THE MOVIE in application:");
    }
}

//Method to Book a single seat for a specific movie and theater
bool BookingManager::bookSeats(const std::string& movieTitle, const std::string& theaterName, const std::string& seatId) {
    std::lock_guard<std::mutex> lock(mutex);
    //Check if the movie exists in the application
    auto movieIt = movies.find(movieTitle);
    if (movieIt == movies.end()) {
        std::cout<<"\nMovie NOT Available"<<std::endl;
        return false; // Movie not found
    }

    auto theaterIt = std::find_if(theaters[movieTitle].begin(), theaters[movieTitle].end(),
        [&](const std::shared_ptr<Theater>& theater) {
            return theater->getName() == theaterName;
        });

    if (theaterIt == theaters[movieTitle].end()) {
        std::cout<<"\n Theater NOT Found:"<<std::endl;
        return false; // Theater not found
    }

    return (*theaterIt)->bookSeat(movieTitle,seatId);
}

//Overloaded Function for Booking multiple seats for a specific movie and theater
bool BookingManager::bookSeats(const std::string& movieTitle, const std::string& theaterName, const std::vector<std::string>& seatIds) {
    std::lock_guard<std::mutex> lock(mutex);

    // Check if the movie exists
    auto movieIt = movies.find(movieTitle);
    if (movieIt == movies.end()) {
        std::cout<<"\nMovie NOT Available"<<std::endl;
        return false; // Movie not found
    }

    // Find the theater showing the particular movie
    auto theaterIt = std::find_if(theaters[movieTitle].begin(), theaters[movieTitle].end(),
                                [&](const std::shared_ptr<Theater>& theater) {
                                    return theater->getName() == theaterName;
                                });

    if (theaterIt == theaters[movieTitle].end()) {
        std::cout<<"\n Theater NOT Found:"<<std::endl;
        return false; // Theater not found
    }

    // Attempt to book all requested seats
    for (const auto& seatId : seatIds) {
        if (!(*theaterIt)->bookSeat(movieTitle,seatId)) {
            return false; // Booking failed for one of the seats
        }
    }

    return true; // All seats booked successfully
}

//Method to get available seats for a particular movie in a particular theater
std::vector<std::shared_ptr<Seat>> BookingManager::getAvailableSeats(const std::string& movieTitle, const std::string& theaterName) const {
    std::lock_guard<std::mutex> lock(mutex);

   // Create a vector to store available seats
    std::vector<std::shared_ptr<Seat>> availableSeats;

    // Check if the movie exists in the map
    auto movieIt = movies.find(movieTitle);
    if (movieIt == movies.end()) {
        std::cout<<"Movie NOT FOUND"<<std::endl;
        return availableSeats; // Movie not found, return empty vector
    }

    // Find the theater that matches the provided name
    auto theaterIt = std::find_if(theaters.at(movieTitle).begin(), theaters.at(movieTitle).end(),
                                [&](const std::shared_ptr<Theater>& theater) {
                                    return theater->getName() == theaterName;
                                });

    if (theaterIt == theaters.at(movieTitle).end()) {
        std::cout<<"\nSORRY :( Theater NOT FOUND"<<std::endl;
        return availableSeats; // Theater not found, return empty vector
    }

    // Retrieve the available seats from the theater and return them
    availableSeats = (*theaterIt)->getAvailableSeats(movieTitle);
    return availableSeats;
}

// Method to get all the playing movies
std::vector<std::string> BookingManager::getAllPlayingMovies() const {
        std::vector<std::string> movieTitles;
        for (const auto& pair : movies) {
            movieTitles.push_back(pair.first);
        }
        return movieTitles;
}

// Method to get the names of all theaters showing a particular movie
std::vector<std::string> BookingManager::getTheatersShowingMovie(const std::string& movieTitle) const {
    std::vector<std::string> theaterNames;

    // Check if the movie exists in the map
    auto theaterIt = theaters.find(movieTitle);
    if (theaterIt != theaters.end()) {
        // Iterate over the vector of theaters and collect their names
        for (const auto& theater : theaterIt->second) {
            theaterNames.push_back(theater->getName());
        }
    }
    else {
        std::cout<<"\nTheater NOT Found for movie:"<<movieTitle<<std::endl;
    }
    return theaterNames;
}

// Function to get booked seats for a specific movie in a specific theater
std::vector<std::shared_ptr<Seat>> BookingManager::getBookedSeats(const std::string& movieTitle, const std::string& theaterName) const {
    // Find the movie by title
    auto movieIt = movies.find(movieTitle);
    if (movieIt == movies.end()) {
        return {}; // Return an empty vector if the movie is not found
    }

    // Find the theater by name
    auto theaterIt = std::find_if(theaters.at(movieTitle).begin(), theaters.at(movieTitle).end(),
                                  [&](const std::shared_ptr<Theater>& theater) {
                                      return theater->getName() == theaterName;
                                  });

    if (theaterIt == theaters.at(movieTitle).end()) {
        return {}; // Return an empty vector if the theater is not found
    }

    // Use the Theater's getBookedSeats function to retrieve the booked seats
    return (*theaterIt)->getBookedSeats(movieTitle);
}
