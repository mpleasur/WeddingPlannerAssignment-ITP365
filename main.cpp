// ITP 365 Spring 2019
// HW4 - Wedding Planner
// Name: Mara Pleasure
// Email: mpleasur@usc.edu
// Platform: Mac
#include "dateconv.h"
#include "HEvent.h"
#include "HCal.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "error.h"
#include <stdlib.h>

HCal* loadCal(std::string fileName){
    //dynamically create a pointer to a calendar object
    HCal *pointCal = new HCal;
    
    //open the input file
    std::ifstream dataFile(fileName);
    //check make sure it opens
    if (!dataFile.is_open()){
        //if this code is run
        //if file didn't open succesfully
        error("File didn't open!");
        
    }
    //get the first line out, since it is just column names
    std::string line;
    std::getline(dataFile, line);
    //now parse through entire file
    while(!dataFile.eof()){
        std::getline(dataFile, line);
        //find first comma
        unsigned long comma1 = line.find(",");
        if (comma1 != std::string::npos){
            //set the date to the string before the first comma
            std::string date = line.substr(0,comma1);
            //get line for second part
            std::string line2 = line.substr(comma1+1);
            //find the next comma
            unsigned long comma2 = line2.find(",");
            //set the name of the holiday to the part after the second comma
            std::string name = line2.substr(comma2+1);
            //convert the epoch date to a long long
            unsigned long long date1 = std::stol(date);
            
            //create a new event dynamically
            HEvent *pointEvent = new HEvent(name,date1);
            
            //add the event to the calendar as a pointer
            pointCal->addEvent(pointEvent);
           // std::cout << pointEvent->getName() << std::endl;
            //create a HEvent object with pointer
            }
    }//end of while loop for data loading here
    //std::cout << pointCal->getSize() <<std::endl;
    
    //return the pointer to the calendar
    return pointCal;
}

HCal* merge(HCal* calA, HCal* calB){
    //create a new dynamic calendar
    HCal* calCpointer = new HCal;
    
    //create two ints to interate through
    int i = 0;
    int j = 0;
    
    //gets sizes of calendars
    int calAsize = calA->getSize();
       int calBsize = calB->getSize();
    
    // Dynamically create a new HCal. This will be the value we return. It will be called HCal C.
   // Create indexes for each of the 2 inputted calendars. Index i will be used to count
    //through HCal A and index j will be used to count through HCal B.
    //.Create a loop that executes while i and j are within range (before the ends of their respective calendars).
          //If the HEvent at A[i] occurs before the HEvent at B[j] add A[i] to the end of C.
            //Then increment i.
            //Otherwise add the event at B[j] to the end of C.
            //Then increment j.
    //When the above loop is over there will be a portion of either A or B left over (it hasn’t been added to C). If A has items remaining, add them to the end of C. If B has items remaining add them to the end of C.
    
    while ((i<calAsize) && (j<calBsize)){
        //gets the events
        HEvent* event1 = calA->getEvent(i);
        HEvent* event2 = calB->getEvent(j);
        //compares the events and adds it depending on this comparison
        if ((*event1) < (*event2)){
            calCpointer->addEvent(event1);
            i = i + 1;
        }
        else{
            calCpointer->addEvent(event2);
            j = j+ 1;
        }
        
        
    }
    //figures out which value j or i is still not at their respective full calendar length
    while (i<calAsize){
        //adds the rest
        HEvent* event1 = calA->getEvent(i);
        calCpointer->addEvent(event1);
        i = i+1;
    }
    while (j<calBsize){
        HEvent* event2 = calB->getEvent(j);
        calCpointer->addEvent(event2);
        j=j+1;
    }
    
    //returns the rest of the calendar
    return calCpointer;
    
}


int main(int argc, char** argv)
{
	
    HCal calUSA;
    HCal calChina;
    HCal calBrazil;
    
    //create three pointers to load the calendar data too
    HCal* usaPoint;
    HCal* chinaPoint;
    HCal* brazilPoint;
    
    //two calendars for merging data from calendars
    HCal* mergedCalender1;
    HCal* mergedCalender2;
    
    //load calendars
    usaPoint = loadCal("USHoliday2016.csv");
    chinaPoint = loadCal("CHholiday2016.csv");
    brazilPoint = loadCal("BRholiday2016.csv");
    
    //std::cout<< usaPoint->getSize() <<std::endl;
    //std::cout<< chinaPoint->getSize()<< std::endl;
    //std::cout<< brazilPoint->getSize()<< std::endl;
    
    //merge calendar 1 and calendar 2
    mergedCalender1 = merge(usaPoint, chinaPoint);
    //then merge those 2 with the 3rd
    mergedCalender2 = merge(mergedCalender1, brazilPoint);
    
    int size = mergedCalender2->getSize();
   
    //for while loop
    int quitVal = 0;
    //for user choice
    std::string choice;
    
    std::cout << "Welcome to the calendar search!" << std::endl;
    while (quitVal ==0){
        std::cout << "Please enter the date to search (MM/DD/YYYY): " << std::endl;
        std::cin >> choice;
        //way for the user to quit
        if (choice == "q"){
            quitVal = 1;
        }
        else if (choice == "Q"){
            quitVal = 1;
        }
        else{
            //convert choice to unsigned int month, unsigned int day, unsigned int year
            
            //find first slash
            unsigned long slash1 = choice.find("/");
            //set that to month
            unsigned int month = stoi(choice.substr(0,slash1));
            //set rest of string to another sub string
            std::string choice2 = choice.substr(slash1+1);
            //find next slash
            unsigned long slash2 = choice2.find("/");
            //set first part to day
            unsigned int day = stoi(choice2.substr(0,slash2));
            //set second part to year
            unsigned int year = stoi(choice2.substr(slash2+1)) ;
       
            //convert those to epoch
             unsigned long long userDate = (getEpochSecs(month, day, year));
            
            //account for daylight savings and pacific coast time
            if ((month > 3) && (month < 11)){
                 userDate = (userDate - 25200);
            }
            else if ((month == 3) && (day >= 13)){
                 userDate = (userDate - 25200);
            }
            else if ((month == 11) && (day <= 6)){
                 userDate = (userDate - 25200);
            }
            else{
                 userDate = (userDate - 28800);
            }
            
            
            
            //create a dynamic event
            HEvent* eventPoint = new HEvent("Wedding Date", userDate);
            
            
            //search for event pointer
            int searchVal = mergedCalender2->search(eventPoint);
            
            //let user know if they picked a good date
            if (searchVal == (-1)){
                std::cout << choice << " is a good day for a Wedding!" << std::endl;
                //quitVal = 1;
            }
            else {
                //print out name of event if it is already taken
                std::cout << choice << " is " << mergedCalender2->getEvent(searchVal)->getName() << std::endl;
            }
            
        }
        
    }
    

    //check user date entered
    //if the date is betweeen march 13th and november 6 subtract 7 hours of seconds from the user inputted date
    //otherwise subtract 8 hours
    
    
    
	return 0;
}
