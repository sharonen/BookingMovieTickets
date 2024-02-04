#include "views.hpp"

using namespace std;
/*
 * The Views class to represent the views of the application
 * This class is a singleton class
 */
Views &Views::getInstance()
{
    static Views instance;
    return instance;
}

// Get all the movies
json Views::getMovies()
{
    // get all the movies from the database
    json j;

    auto movies = DB::getInstance().getMovies();
    for (auto movie : movies)
    {
        j.push_back({{"name", movie->getMovieName()}, {"description", movie->getMovieDescription()}});
    }
    // return the movies in the form of json
    return j;
}

// Get all the theaters showing a given movie
json Views::getTheaters(string movieName)
{
    json j;
    auto movieTheaters = DB::getInstance().getMovieTheaters(movieName);
    for (auto movieTheater : movieTheaters)
    {
        j.push_back({{"name", movieTheater->getTheater()->getTheaterName()}, {"location", movieTheater->getTheater()->getTheaterLocation()}});
    }
    return j;
}

// Get all the available seats for a given theater and a given movie
json Views::getAvailableSeats(string movieName, string theaterName)
{
    json j;
    auto movieTheater = DB::getInstance().getMovieTheater(movieName, theaterName);
    if (movieTheater == nullptr)
    {
        return {{"status", "failed"}, {"message", "The movie or theater does not exist"}};
    }
    auto seats = movieTheater->getAvailableSeats();
    for (auto seat : seats)
    {
        char seatRow = seat[0];
        int seatNumber = stoi(seat.substr(1));
        j.push_back({{"row", seatRow}, {"number", seatNumber}});
    }
    return j;
}

// Book seats for a given movie and theater
json Views::bookSeats(vector<string> seatNumbers, string movieName, string theaterName)
{
    auto movieTheater = DB::getInstance().getMovieTheater(movieName, theaterName);
    if (movieTheater == nullptr)
    {
        return {{"status", "failed"}, {"message", "The movie or theater does not exist"}};
    }
    // Check all seats are available
    if (!movieTheater->checkSeats(seatNumbers))
    {
        return {{"status", "failed"}, {"message", "Some of the seats are already booked, please try again with different seats"}};
    }
    // Book the seats
    bool booked = movieTheater->bookSeat(seatNumbers);
    if (!booked)
    {
        return {{"status", " failed"}, {"message", "Something went wrong, please try again later"}};
    }
    return {{"status", "success"}, {"message", "Your seats have been booked successfully"}};
}
