#include <iostream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#include "../db/db.hpp"

using namespace std;
using json = nlohmann::json;

class Views
{
private:
    Views() {}

public:
    // Delete the copy constructor and assignment operator
    Views(const Views &) = delete;
    Views &operator=(const Views &) = delete;

    /*
     * Get the instance of the DB
     * @return reference to the DB object
     */
    static Views &getInstance();

    /*
     * API call to get all the moviews
     * @return: A json object containing all the movies names and descriptions
     */
    json getMovies();

    /*
     * API call to get all the theaters showing a given movie
     * @param movieName: The name of the movie
     * @return: A json object containing all the theaters showing the given movie
     */
    json getTheaters(string movieName);

    /*
     * API call to get all the available seats for a given theater and a given movie
     * @param movieName: The name of the movie
     * @param theaterName: The name of the theater
     * @return: A json object containing all the available seats
     */
    json getAvailableSeats(string movieName, string theaterName);

    /*
     * API call to book seats for a given movie and theater
     * @param seatNumbers: The seat numbers to be booked
     * @param movieName: The name of the movie
     * @param theaterName: The name of the theater
     * @return: A json object containing the status of the booking
     */
    json bookSeats(vector<string> seatNumbers, string movieName, string theaterName);
};