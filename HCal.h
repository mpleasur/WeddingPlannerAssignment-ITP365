// ITP 365 Spring 2019
// HW4 - Wedding Planner
// Name: Mara Pleasure
// Email: mpleasur@usc.edu
// Platform: Mac

#include <string>
#include <vector>
#include "HEvent.h"

#ifndef HCal_h
#define HCal_h

class HCal{
protected:
    //member variable
    std::vector<HEvent*> mHolidays;
    
public:
    //function: HCal default constructor
    //parameters: nothing
    //returns: nothing
    //purpose: create a HCal Object
    HCal();
    
    //function: addEvent
    //parameters: a pointer to a HEvent object
    //returns: nothing
    //purpose: add the pointer to the vector of pointers
    void addEvent(HEvent* inEventPoint);
    
    //function: getSize
    //parameters: nothing
    //returns: size of vector
    //purpose: return the size of the vector of pointers
    int getSize();
    
    //function: getEvent
    //parameters: eventNum
    //returns: a pointer to that event
    //purpose: gets pointer at the int of the vector of pointers
    HEvent* getEvent(unsigned int eventNum);
    
    //function: binarySearchPart
    //parameters: event pointer, int start, int end
    //returns: int
    //purpose: gets the events int
    int binarySearchP(HEvent* eventPoint, unsigned int start, unsigned int end);
    
    //function: search
    //parameters: event pointer, int start, int end
    //returns: location of event
    //purpose: search through a vector of pointers to find matching pointer
    int search(HEvent* eventPoint);
};




#endif /* HCal_h */
