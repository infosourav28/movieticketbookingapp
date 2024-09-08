#ifndef MOVIE_HPP
#define MOVIE_HPP

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

class BOOKING_API Movie {
    std::string title;
    std::string genre;
    int duration;

public:
    Movie()=default;

    //Parameterized constuctor for Initialization 
    Movie(const std::string& title, const std::string& genre, int duration);
    
    //Get functions for reading values of Movie Title, Genre and Duration
    const std::string& getTitle() const;
    const std::string& getGenre() const;
    int getDuration() const;

    // Destructor
    ~Movie() = default;

    // Move Constructor
    Movie(Movie&& other) noexcept;
    // Move Assignment Operator
    Movie& operator=(Movie&& other) noexcept;
    
    // Delete copy constructor and copy assignment operator
    Movie(const Movie&) = delete;
    Movie& operator=(const Movie&) = delete;
};

#endif // MOVIE_HPP
