#ifndef DB_H
#define DB_H

#include <iostream>
#include <vector>
#include "../movie/movie.hpp"
#include "../theater/theater.hpp"
#include "../movie_theater/movieTheater.hpp"
using namespace std;

/*
 * DB class to represent the database
 * For brevity, we are only considering the movies, theaters and movie theaters
 * For complete implementation, we can consider other entities like users, bookings, reviews etc.
 */
class DB
{
    vector<Movie *> movies;
    vector<Theater *> theaters;
    vector<MovieTheater *> movieTheaters;
    /*
     * Constructor for the DB, there should be only one instance of the DB
     */
    DB() {}

public:
    // Delete the copy constructor and assignment operator
    DB(const DB &) = delete;
    DB &operator=(const DB &) = delete;

    /*
     * Get the instance of the DB
     * @return reference to the DB object
     */
    static DB &getInstance();

    /* clear the db */
    void clearDB();

    /* Add Movie to the db
     * @param movie - pointer to Movie object to be added to the db
     */
    void addMovie(Movie *movie);

    /* Add Theater to the db
     * @param theater - pointer to Theater object to be added to the db
     */
    void addTheater(Theater *theater);

    /* Add MovieTheater to the db
     * @param movieTheater - pointer to MovieTheater object to be added to the db
     */
    void addMovieTheater(MovieTheater *movieTheater);

    /* Get all the movies from the db
     * @return vector of Movie objects
     */
    vector<Movie *> getMovies();

    /* Get all the theaters from the db
     * @return vector of Theater objects
     */
    vector<Theater *> getTheaters();

    /* Get all the movie theaters from the db
     * @param movieName - name of the movie
     * @return vector of MovieTheater objects
     */
    vector<MovieTheater *> getMovieTheaters(string movieName);

    /* Get the movie theater from the db
     * @param movieName - name of the movie
     * @param theaterName - name of the theater
     * @return pointer to the MovieTheater object
     */
    MovieTheater *getMovieTheater(string movieName, string theaterName);
};

#endif