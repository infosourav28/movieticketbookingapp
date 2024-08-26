#include "movie_factory.hpp"

Movie MovieFactory::createMovie(const std::string& title, const std::string& genre, int duration) {
    return Movie(title, genre, duration);
}
