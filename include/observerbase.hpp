#ifndef OBSERVERBASE_HPP
#define OBSERVERBASE_HPP

#include "event.hpp"

class ObserverBase {
public:
    virtual void update(Event* event) = 0;  // The UI will implement this
    virtual ~ObserverBase() = default;
};

#endif