#ifndef OBSERVERBASE_HPP
#define OBSERVERBASE_HPP

#include "event.hpp"

#ifdef _WIN32
    #ifdef BOOKING_EXPORTS
        #define BOOKING_API __declspec(dllexport)
    #else
        #define BOOKING_API __declspec(dllimport)
    #endif
#else
    #define BOOKING_API __attribute__((visibility("default")))
#endif

class BOOKING_API ObserverBase {
public:
    virtual void update(Event* event) = 0;  // The UI will implement this
    virtual ~ObserverBase() = default;
};

#endif