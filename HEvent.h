//
// ITP 365 Spring 2019
// HW4 - Wedding Planner
// Name: Mara Pleasure
// Email: mpleasur@usc.edu
// Platform: Mac


#include <iostream>
#include <string>
#include "dateconv.h"

#ifndef HEvent_h
#define HEvent_h



class HEvent{
private:
    //member variables
    std::string mName;
    unsigned long long mDate;
    
public:
    //function: parameterized constructor
    //parameters: string of name, long long of date
    //returns: nothing
    //purpose: create a HEvent object
    HEvent(std::string inName, unsigned long long inDate);
    
    //function: getName
    //parameters: nothing
    //returns: returns the name of the Event
    //purpose: get the name of the event
    std::string getName();
    
    //function: getDate
    //parameters: nothing
    //returns: a unsigned long long that is the date of the event
    //purpose: to get the date of the event
    unsigned long long getDate();
    
    //function: operator == overload function
    //parameters: two Events
    //returns: true or false
    //purpose: To determmine if the two events are at the same time
    friend bool operator== (HEvent& event1, HEvent& event2);
    
    //function: operator < overload function
    //parameters: two HEvent objects
    //returns: true or false
    //purpose: determines if event 1 is less than event 2
    friend bool operator< (HEvent& event1, HEvent& event2);
    
    //function: operator << overload function
    //parameters: output stream, event object
    //returns: nothing
    //purpose: prints out to the output stream the event in the format I want
    friend std::ostream& operator<< (std::ostream& os, HEvent& event);
};




#endif /* HEvent_h */
