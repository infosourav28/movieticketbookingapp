#include "theater_factory.hpp"

Theater TheaterFactory::createTheater(const std::string& name) {
    return Theater(name);
}
