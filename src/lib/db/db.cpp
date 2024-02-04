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
/*
 * Intialise the db with some data
 */
void DB::initDB()
{
    Movie *movie1 = new Movie("Anyone But You", "after an amazing first date something happens that turns their fiery hot attraction ice cold — until they find themselves unexpectedly thrust together at a destination wedding in Australia. So they do what any two mature adults would do - pretend to be a couple");
    Movie *movie2 = new Movie("The Beekeeper", "The fast-paced action-thriller, which is steeped in the mythology of beekeeping, follows a man's personal journey of vengeance which takes on national stakes after he is revealed to be a former operative of a powerful and clandestine organization known as the ‘Beekeepers’.");

    Movie *movie3 = new Movie("Priscilla", "When teenage Priscilla Beaulieu meets Elvis Presley at a party, the man who is already a meteoric rock-and-roll superstar becomes someone entirely unexpected in private moments: a thrilling crush, an ally in loneliness, a vulnerable best friend who speaks with her in a language few others understand.");

    movies.push_back(movie1);
    movies.push_back(movie2);
    movies.push_back(movie3);

    Theater *theater1 = new Theater(20, "Theater 1", "New York");
    Theater *theater2 = new Theater(20, "Theater 2", "Los Angeles");
    Theater *theater3 = new Theater(20, "Theater 3", "Chicago");
    theaters.push_back(theater1);
    theaters.push_back(theater2);
    theaters.push_back(theater3);

    MovieTheater *movieTheater = new MovieTheater(movie1, theater1);
    MovieTheater *movieTheater2 = new MovieTheater(movie1, theater2);
    MovieTheater *movieTheater3 = new MovieTheater(movie1, theater3);
    MovieTheater *movieTheater4 = new MovieTheater(movie2, theater1);
    MovieTheater *movieTheater5 = new MovieTheater(movie2, theater2);
    MovieTheater *movieTheater6 = new MovieTheater(movie3, theater1);
    MovieTheater *movieTheater7 = new MovieTheater(movie3, theater2);
    MovieTheater *movieTheater8 = new MovieTheater(movie3, theater3);
    movieTheaters.push_back(movieTheater);
    movieTheaters.push_back(movieTheater2);
    movieTheaters.push_back(movieTheater3);
    movieTheaters.push_back(movieTheater4);
    movieTheaters.push_back(movieTheater5);
    movieTheaters.push_back(movieTheater6);
    movieTheaters.push_back(movieTheater7);
    movieTheaters.push_back(movieTheater8);
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