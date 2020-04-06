// ITP 365 Spring 2019
// HW4 - Wedding Planner
// Name: Mara Pleasure
// Email: mpleasur@usc.edu
// Platform: Mac

#include <stdio.h>
#include "HCal.h"

//implementation of constructor
HCal::HCal(){
    mHolidays.clear();
}

//implementation of addEvent
void HCal::addEvent(HEvent* inEventPoint){
    mHolidays.push_back(inEventPoint);
}

//implementation of getSize
int HCal::getSize(){
    return mHolidays.size();
}

//implementation of getEvent
HEvent* HCal::getEvent(unsigned int eventNum){
    return mHolidays[eventNum];
}

//implementation of binary search p
int HCal::binarySearchP(HEvent* eventPoint, unsigned int start, unsigned int end){
    //get the date of the event pointer
    unsigned long long date = eventPoint->getDate();
    if (end<start){
        return -1;
    }
    //get middle index between start and end, splitting size in half
    int middleIndex = (end+start)/2;
    
    //compare the middle index date to the date of the inputted pointer
    if (mHolidays[middleIndex]->getDate() == date) {
        return middleIndex;
    }
    
    if (mHolidays[middleIndex]->getDate() > date){
        //binary search first half recursively
        return binarySearchP(eventPoint, start, (middleIndex-1));
        
        
    } else{
        //binary search second half recurisvely
        return binarySearchP(eventPoint, (middleIndex + 1), end);
    }
    
    //return 0;
}

//implementation of search
int HCal::search(HEvent* eventPoint){
    //calls it for the length of the vector - 1
    return binarySearchP(eventPoint, 0, (mHolidays.size()-1));
    

}
