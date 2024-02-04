#ifndef MOVIETHEATER_H
#define MOVIETHEATER_H

#include <iostream>
#include <vector>
#include <string>
#include <mutex>

#include "../movie/movie.hpp"
#include "../theater/theater.hpp"

using namespace std;

/*
 * MovieTheater class to represent realstionship between Movie and Theater
 * Assumption there are 5 rows in the theater
 * In the theater, the seats are represented as a combination of row and seat number (e.g a1, a2, a3, a4, a5, b1, b2, b3, b4, b5, c1, c2, c3, c4, c5, d1, d2, d3, d4, d5, e1, e2, e3, e4, e5)
 * For brevity, I am only considering the movie, theater, and available seats
 * For more complete solution, we can consider the show timings, ticket prices, etc.
 */

class MovieTheater
{
private:
    Movie *movie;
    Theater *theater;
    unordered_map<string, bool> availableSeats;
    std::mutex mu_;

public:
    /*
    Constructor to initialize the movie and theater
    @param movie - pointer to Movie object
    @param theater - pointer to Theater object
    */
    MovieTheater(Movie *movie, Theater *theater);

    /*
    Get the movie object
    @return the movie object
    */
    Movie *getMovie();

    /*
    Get the movie description
    @return the movie description
    */
    Theater *getTheater();

    /*
    Get the available seats
    @return vector of the available seats
    */
    vector<string> getAvailableSeats();

    /*
    Book a seat
    @param seatNumbers - vector of seat numbers to book
    @return true if the seats are booked, false otherwise
    */
    bool bookSeat(vector<string> seatNumbers);

    /*
    Cancel seats
    @param seatNumbers - vector of seat numbers to cancel
    */
    void cancelSeats(vector<string> seatNumbers);

    /*
    Check if the seats are available
    @param seatNumbers - vector of seat numbers to check
    @return true if the seats are available, false otherwise
    */
    bool checkSeats(vector<string> seatNumbers);
};

#endif