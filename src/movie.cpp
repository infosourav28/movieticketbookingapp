#include "movie.hpp"

//Parametrized constructor
Movie::Movie(const std::string& title, const std::string& genre, int duration)
    : title(title), genre(genre), duration(duration) {}

//Function to get movie title
const std::string& Movie::getTitle() const { return title; }

//Function to get genre of the movie
const std::string& Movie::getGenre() const { return genre; }

//Function to get duration of the movie
int Movie::getDuration() const { return duration; }

//Move Constructor
Movie::Movie(Movie&& other) noexcept
        : title(std::move(other.title)), genre(std::move(other.genre)), duration(other.duration) {
        other.duration = 0;
    }

//Move assignment operator
Movie& Movie::operator=(Movie&& other) noexcept {
    if (this != &other) {
        title = std::move(other.title);
        genre = std::move(other.genre);
        duration = other.duration;
        other.duration = 0;
    }
    return *this;
}
