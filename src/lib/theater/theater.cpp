#include "theater.hpp"

using namespace std;

Theater::Theater(int theaterCapacity, string theaterName, string theaterLocation)
{
    this->theaterCapacity = theaterCapacity;
    this->theaterName = theaterName;
    this->theaterLocation = theaterLocation;
}

// Get the theater capacity
int Theater::getTheaterCapacity()
{
    return theaterCapacity;
}
// Get the theater name
string Theater::getTheaterName()
{
    return theaterName;
}
// Get the theater location
string Theater::getTheaterLocation()
{
    return theaterLocation;
}

// Set the theater name
void Theater::setTheaterName(string theaterName)
{
    this->theaterName = theaterName;
}

// Set the theater location
void Theater::setTheaterLocation(string theaterLocation)
{
    this->theaterLocation = theaterLocation;
}