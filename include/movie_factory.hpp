#ifndef MOVIE_FACTORY_HPP
#define MOVIE_FACTORY_HPP

#include "movie.hpp"

class MovieFactory {
public:
    static Movie createMovie(const std::string& title, const std::string& genre, int duration);
};

#endif // MOVIE_FACTORY_HPP
