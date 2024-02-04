#include "movie.hpp"

// Constructor for Movie
Movie::Movie(string name, string description)
{
    movieName = name;
    movieDescription = description;
}
// Get the movie name
string Movie::getMovieName()
{
    return movieName;
}
// Get the movie description
string Movie::getMovieDescription()
{
    return movieDescription;
}
// Set the movie name
void Movie::setMovieName(string name)
{
    movieName = name;
}
// Set the movie description
void Movie::setMovieDescription(string description)
{
    movieDescription = description;
}