#include <iostream>
#include <vector>
#include "db.hpp"

using namespace std;

/*
 * The DB class is a singleton class that holds the data for the movies, theaters and movie theaters
 */
DB &DB::getInstance()
{
    static DB instance;
    return instance;
}
// Clear the db
void DB::clearDB()
{
    movies.clear();
    theaters.clear();
    movieTheaters.clear();
}
// Add a movie to the db
void DB::addMovie(Movie *movie)
{
    movies.push_back(movie);
}
// Add a theater to the db
void DB::addTheater(Theater *theater)
{
    theaters.push_back(theater);
}
// Add a movie theater to the db
void DB::addMovieTheater(MovieTheater *movieTheater)
{
    movieTheaters.push_back(movieTheater);
}
//
vector<Movie *> DB::getMovies()
{
    return movies;
}
// Get all the theaters from the db
vector<Theater *> DB::getTheaters()
{
    return theaters;
}
// Get all the movie theaters from the db
vector<MovieTheater *> DB::getMovieTheaters(string movieName)
{
    vector<MovieTheater *> movieTheatersResult;
    for (auto movieTheater : movieTheaters)
    {
        if (movieTheater->getMovie()->getMovieName().compare(movieName) == 0)
        {
            movieTheatersResult.push_back(movieTheater);
        }
    }
    return movieTheatersResult;
}
// Get a movie theater from the db
MovieTheater *DB::getMovieTheater(string movieName, string theaterName)
{

    for (auto movieTheater : movieTheaters)
    {
        if (movieTheater->getMovie()->getMovieName().compare(movieName) == 0 && movieTheater->getTheater()->getTheaterName().compare(theaterName) == 0)
        {
            return movieTheater;
        }
    }
    return nullptr;
}