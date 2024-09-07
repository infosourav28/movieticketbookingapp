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
  * movieTitle: The title of the movie.
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

# ObserverBase Interface API Documentation:
## Overview

The `ObserverBase` class is an abstract interface that defines the contract for any observer in an event-driven system. It allows objects to be notified of changes or updates when an `Event` occurs. The observer pattern is typically used to achieve loose coupling between objects, where an observer (like the UI class) is updated based on the state changes of another object or system component (via events).

Classes that derive from `ObserverBase` must implement the `update()` method, which handles the notification logic when an event occurs.

## Header file
```C++
#ifndef OBSERVERBASE_HPP
#define OBSERVERBASE_HPP

#include "event.hpp"

class ObserverBase {
public:
    // The UI will implement this method to update itself based on the event
    virtual void update(Event* event) = 0;

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~ObserverBase() = default;
};

#endif

```
## Class: `ObserverBase`
## Public Methods
`virtual void update(Event* event) = 0 `
* **Description:** This pure virtual method must be implemented by any class that derives from ObserverBase. The update() method is called whenever an event occurs, allowing the observer to handle the event accordingly.
* **Parameters:**
    * **event:** A pointer to the Event object, representing the event that has occurred. This is typically a polymorphic type, allowing different event types (e.g., MovieEvent, TheaterEvent, etc.) to be handled by the observer.
    * **Returns:** void
    * **Usage:**
    This method must be overridden in derived classes like UI.

```C++
class UI : public ObserverBase {
    void update(Event* event) override {
        // Handle the event
    }
};

```

`virtual ~ObserverBase() = default`
* **Description:** A virtual destructor to ensure that derived classes are properly destroyed when the base class is deleted. This ensures that resources managed by derived classes are properly cleaned up.
* **Parameters:** None.
* **Returns:** void

**Purpose:** ObserverBase serves as the base interface for all observer objects in an event-driven system. It provides a flexible mechanism for handling notifications about events without tightly coupling the observer to the event source.

**Implementation:** Any class deriving from ObserverBase must implement the update(Event* event) method. This allows the observer to react to the event when it is notified.

# UI Class API Documentation:
## Overview
The UI class is responsible for managing and displaying updates in response to various events in a movie booking system. It implements the `ObserverBase` interface and updates the user interface by handling different types of events such as movie events, theater events, booking events, and query events. This class provides a centralized way to reflect changes in the system to the user interface.
It is shown in this back end application as an example to get the data in the UI / embedded CLI front end.

If you need **to integrate your own UI/CLI class**, then you need to implement the `ObserverBase` interface and include your own **ui.hpp** file additionally as shown in **main.cpp**

## Class: `UI`
Similar to the below functions your own CLI/ UI class should have the functions.
## Public Methods :
`void update(Event* event)`
* **Description:** Overrides the ObserverBase class's update method. This method receives an event and calls the appropriate handler based on the event's type.
* **Parameters:**
  * **event:** A pointer to the Event object. This is a polymorphic object representing different event types such as MovieEvent, TheaterEvent, BookingEvent, etc.
  * **Returns:** void

## Private Methods :
`void handleMovieEvent(MovieEvent* event)`
* **Description:** Handles updates related to movies in the UI. Typically triggered when a MovieEvent is received.
* **Parameters:**
  * **event:** A pointer to the MovieEvent object, which contains movie-specific information such as movie title and description.
  * **Returns:** void

`void handleTheaterEvent(TheaterEvent* event)`
* **Description:** Handles updates related to theaters in the UI. Triggered when a TheaterEvent is received, and provides information such as theater name and movie title.
* **Parameters:**
  * **event:** A pointer to the TheaterEvent object, which contains details about the theater and movie.
  * **Returns:** void

`void handleBookingEvent(BookingEvent* event)`
* **Description:** Handles updates related to bookings in the UI. Triggered when a BookingEvent is received, and provides details about the movie, theater, and seat.
* **Parameters:**
  * **event:** A pointer to the BookingEvent object, which contains booking details like movie title, theater name, and seat ID.
  * **Returns:** void

`void handleSeatQueryEvent(const SeatQueryEvent* event)`

* **Description:** Handles updates related to seat availability in the UI. Triggered when a SeatQueryEvent is received, displaying information about available seats for a movie in a particular theater.
* **Parameters:**
  * **event:** A constant pointer to the SeatQueryEvent object, which contains details about seat availability, movie title, and theater name.
  * **Returns:** void

`void handleMovieListQueryEvent(const MovieListQueryEvent* event)`

* **Description:** Handles updates related to movie listings in the UI. Triggered when a MovieListQueryEvent is received, displaying the list of currently playing movies.
* **Parameters:**
  * **event:** A constant pointer to the MovieListQueryEvent object, which contains a list of currently available movie titles.
  * **Returns:** void

`void handleTheaterListQueryEvent(const TheaterListQueryEvent* event)`

* **Description:** Handles updates related to theater listings in the UI. Triggered when a TheaterListQueryEvent is received, showing the list of theaters that are screening a specific movie.
* **Parameters:**
  * **event:** A constant pointer to the TheaterListQueryEvent object, which contains the movie title and a list of theater names.
  * **Returns:** void

## Example Usage: In `main.cpp`
```C++
#include "booking_manager.hpp"
#include "ui.hpp"

int main(){

// Create booking manager
BookingManager& manager = BookingManager::getInstance();

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
```
