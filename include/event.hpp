#ifndef EVENT_HPP
#define EVENT_HPP

#include<string>

class Event {
public:
    virtual ~Event() = default;
    virtual std::string getType() const = 0;  // Type of event
};


#endif