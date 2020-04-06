// ITP 365 Spring 2019
// HW4 - Wedding Planner
// Name: Mara Pleasure
// Email: mpleasur@usc.edu
// Platform: Mac

#include <stdio.h>
#include "HEvent.h"

//implementation of parametized constructor
HEvent::HEvent(std::string inName, unsigned long long inDate){
    mName = inName;
    mDate = inDate;
}

//implementation of get name function
std::string HEvent::getName(){
    return mName;
}

//implementation of get date function
unsigned long long  HEvent::getDate(){
    return mDate;
}

//implementation of == overload function
bool operator== (HEvent& event1, HEvent& event2){
    if (event1.mDate == event2.mDate){
        return true;
    }
    else {
        return false;
    }
}

//implementation of < overload function
bool operator< (HEvent& event1, HEvent& event2){
    if (event1.mDate < event2.mDate){
        return true;
    }
    else {
        return false;
    }
}

//implementation of os stream operator overload function
std::ostream& operator<< (std::ostream& os, HEvent& event){
    //operator overload, just making a way for it to print out nicely.
    unsigned int month = getMonth(event.mDate);
    unsigned int day = getMonthDay(event.mDate);
    unsigned int year = getYear(event.mDate);
    os <<month <<"/"<<day<< "/" << year << " is " << event.mName;
    
    return os;
}
