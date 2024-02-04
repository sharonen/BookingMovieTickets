#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * Movie class to represent the movie
 * For brevity, we are only considering the name and description of the movie
 * For complete implementation, we can consider other attributes like genre, rating, link to *  trailer etc.
 */
class Movie
{
private:
   string movieName;
   string movieDescription;

public:
   /*  Constructor for the Movie class
       @param name: The name of the movie
       @param description: The description of the movie
   */
   Movie(string name, string description);

   /* Get the movie name
      @return: The name of the movie
   */
   string getMovieName();

   /* Get the movie description
      @return: The description of the movie
   */
   string getMovieDescription();

   /* Set the movie name
      @param name: The name of the movie
   */
   void setMovieName(string name);

   /* Set the movie description
      @param description: The description of the movie
   */
   void setMovieDescription(string description);
};

#endif