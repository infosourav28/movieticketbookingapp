#ifndef THEATER_FACTORY_HPP
#define THEATER_FACTORY_HPP

#include "theater.hpp"

class TheaterFactory {
public:
    static Theater createTheater(const std::string& name);
};

#endif // THEATER_FACTORY_HPP
