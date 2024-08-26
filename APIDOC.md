# BookingManager Class API Documentation:

This API documentation provides a comprehensive overview of the BookingManager class and its functionality, ensuring developers can effectively integrate it into their applications.

## CLASS OVERVIEW:

The BookingManager class is a singleton class responsible for managing movie bookings.
It provides functionalities to add movies and theaters, book seats, retrieve available and booked seats, and list all playing movies and the theaters showing a specific movie.
This class is thread-safe, utilizing mutexes to protect shared resources.

## PUBLIC METHODS:
`BookingManager& getInstance()`
* **Description:** Implementation of Meyers Singleton through which a single instance of BookingManager is obtained.This ensures that throughout the lifecycle of the program only one instance of BookingManager exists to avoid duplicacy.

* **Returns:** A reference to the singleton BookingManager instance (One & Only).

`void addMovie(std::shared_ptr<Movie> movie)`

* **Description:** Adds a new movie to the booking manager.
* **Parameters:** movie: A shared_ptr to a Movie object to be added.

`void addTheater(const std::string& movieTitle, std::shared_ptr<Theater> theater)`

* **Description:** Associates a theater with a specific movie. This method also initializes seats for the specified movie in the given theater.
* **Parameters:**
movieTitle: The title of the movie.
theater: A shared_ptr to a Theater object to be associated with the movie.

`bool bookSeats(const std::string& movieTitle, const std::string& theaterName, const std::string& seatId)`

* **Description:** Books a single seat for a specific movie in a specific theater.
* **Parameters:**
 * movieTitle: The title of the movie.
 * theaterName: The name of the theater.
 * seatId: The ID of the seat to be booked.
* **Returns:** true if the seat is successfully booked; false otherwise.

`bool bookSeats(const std::string& movieTitle, const std::string& theaterName, const std::vector<std::string>& seatIds)`

* **Description:** Books multiple seats for a specific movie in a specific theater.This is an overloaded function.
* **Parameters:**
 * movieTitle: The title of the movie.
 * theaterName: The name of the theater.
 * seatIds: A vector of seat IDs to be booked.
* **Returns:** true if all seats are successfully booked; false otherwise.

`std::vector<std::shared_ptr<Seat>> getAvailableSeats(const std::string& movieTitle, const std::string& theaterName) const`
* **Description:** Retrieves a list of all available seats for a particular movie in a particular theater.
* **Parameters:**
 * movieTitle: The title of the movie.
 * theaterName: The name of the theater.
* **Returns:** A vector of shared_ptr to Seat objects representing the available seats. Returns an empty vector if the movie or theater is not found.

`std::vector<std::string> getAllPlayingMovies() const`
* **Description:** Retrieves a list of titles for all movies currently managed by the booking system.
* **Returns:** A vector of strings representing the titles of all playing movies.

`std::vector<std::string> getTheatersShowingMovie(const std::string& movieTitle) const`
* **Description:** Retrieves a list of theater names showing a specific movie.
* **Parameters:**
  * movieTitle: The title of the movie.
* **Returns:** A vector of strings representing the names of theaters showing the specified movie. Returns an empty vector if the movie is not found.

`std::vector<std::shared_ptr<Seat>> getBookedSeats(const std::string& movieTitle, const std::string& theaterName) const`
* **Description:** Retrieves a list of all booked seats for a particular movie in a particular theater.
* **Parameters:**
  * movieTitle: The title of the movie.
  * theaterName: The name of the theater.
* **Returns:** A vector of shared_ptr to Seat objects representing the booked seats. Returns an empty vector if the movie or theater is not found.

### Thread Safety
All public methods in the BookingManager class are thread-safe, utilizing mutexes to protect shared resources and ensure consistent state across multiple threads.

### Usage Example
```C++
BookingManager& manager = BookingManager::getInstance();

// Create some movies with genre and duration
auto movie1 = std::make_shared<Movie>("Fast & Furious", "Action", 120);
manager.addMovie(movie1);


// Create theaters
auto theater1 = std::make_shared<Theater>("Theater1:IMAX");
manager.addTheater(movie1->getTitle(), theater1);

// View and display all playing movies
auto playingMovies = manager.getAllPlayingMovies();
std::cout << "\nCurrently playing movies:" << std::endl;
for (const auto& title : playingMovies) {
   std::cout << "- " << title << std::endl;
}

// View and display all theaters showing "Fast & Furious"
auto theatersForMovie2 = manager.getTheatersShowingMovie("Fast & Furious");
std::cout << "\nAll the Theaters showing 'Fast & Furious':" << std::endl;
for (const auto& theaterName : theatersForMovie2) {
    std::cout << "- " << theaterName << std::endl;
}

bool successval = manager.bookSeats("Fast & Furious", "Theater1:IMAX", "a1");

// View & Display available seats
 std::cout << "\n\nAvailable seats in Theater1:IMAX for Fast & Furious:" << std::endl;
 auto availableSeats = manager.getAvailableSeats("Fast & Furious", "Theater1:IMAX");
 for (const auto& seat : availableSeats) {
     std::cout << seat->getSeatId() << "  ";
 }

```
This example demonstrates how to get the BookingManager instance, add a movie and a theater,get currently playing movies, view and display the theaters showing a particular movie and book a seat and view available Seats for a particular movie. For more detailed examples refer **main.cpp** file.

### Additional Wrapper Functions in **main.cpp** file
There are some reference wrapper functions which can be used by thread functionality to pass the data to the BookingManager class API. Also, these functions can be direclty used to print the returned values from BookingManager APIs.They are as following:

`void bookSingleSeat(const std::string& movieTitle, const std::string& theaterName, const std::string& seatId)`

* **Description:** Wrapper Function to book a single seat. It uses bookSeats API of BookingManager class
* **Parameters:**
    * movieTitle: The title of the movie.
    * theaterName: The name of the theater.
    * seatID: Single seatID to be booked

`void bookMultipleSeats(const std::string& movieTitle, const std::string& theaterName, const std::vector<std::string>& seatIds)`

* **Description:** Wrapper Function to book multiple seats. It uses overloaded bookSeats API of BookingManager class
* **Parameters:**
    * movieTitle: The title of the movie.
    * theaterName: The name of the theater.
    * seatIDs: vector of multiple seats to be booked

`void getAvailableSeats(const std::string& movieTitle, const std::string& theaterName)`

* **Description:** Wrapper Function to get & display the number of available seats & their IDs
* **Parameters:**
    * movieTitle: The title of the movie.
    * theaterName: The name of the theater.

`void setupBookingSystem()`
* **Description:** Helper function to add movies and theaters. It uses addMovie() and addTheater() API of  BookingManager Class to create new movies & adding those movies in the theaters
