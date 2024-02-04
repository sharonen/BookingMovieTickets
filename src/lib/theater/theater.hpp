#ifndef THEATER_H
#define THEATER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * Theater class to represent the theater
 * For brevity, I am only considering the name, location, and capacity of the theater
 * For complete implementation, we can consider other attributes like address, contact details, etc.
 */
class Theater
{
private:
    int theaterCapacity;
    string theaterName;
    string theaterLocation;

public:
    /*
     * Constructor for Theater
     * @param theaterCapacity - the capacity of the theater
     * @param theaterName - the name of the theater
     * @param theaterLocation - the location of the theater
     */
    Theater(int theaterCapacity, string theaterName, string theaterLocation);

    /*
     * Get the theater capacity
     * @return the capacity of the theater
     */
    int getTheaterCapacity();

    /*
     * Get the theater name
     * @return the name of the theater
     */
    string getTheaterName();

    /*
     * Get the theater location
     * @return the location of the theater
     */
    string getTheaterLocation();

    /*
     * Set the theater name
     * @param theaterName - the name of the theater
     */
    void setTheaterName(string theaterName);

    /*
     * Set the theater location
     * @param theaterLocation - the location of the theater
     */
    void setTheaterLocation(string theaterLocation);
};

#endif