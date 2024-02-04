#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "../src/lib/movie/movie.hpp"
#include "../src/lib/theater/theater.hpp"
#include "../src/lib/movie_theater/movieTheater.hpp"
#include "../src/lib/db/db.hpp"
#include "../src/lib/views/views.hpp"

TEST_CASE("Checking Movie")
{
    GIVEN("a Movie object")
    {
        auto movie = new Movie("The Dark Knight", "A movie about Batman");
        THEN("the movie name and description are as expected")
        {
            REQUIRE(movie->getMovieName() == "The Dark Knight");
            REQUIRE(movie->getMovieDescription() == "A movie about Batman");
        }
        THEN("the movie name and description can be changed")
        {
            movie->setMovieName("The Dark Knight Rises");
            movie->setMovieDescription("A movie about Batman and Bane");
            REQUIRE(movie->getMovieName() == "The Dark Knight Rises");
            REQUIRE(movie->getMovieDescription() == "A movie about Batman and Bane");
        }
    }
}

TEST_CASE("Checking Theater")
{
    GIVEN("a Theater object")
    {
        auto theater = new Theater(25, "Regal Cinemas", "New York");
        THEN("the theater capacity, name and location are as expected")
        {
            REQUIRE(theater->getTheaterCapacity() == 25);
            REQUIRE(theater->getTheaterName() == "Regal Cinemas");
            REQUIRE(theater->getTheaterLocation() == "New York");
        }
        THEN("the theater name and location can be changed")
        {
            theater->setTheaterName("AMC");
            theater->setTheaterLocation("New Jersey");
            REQUIRE(theater->getTheaterName() == "AMC");
            REQUIRE(theater->getTheaterLocation() == "New Jersey");
        }
    }
}

TEST_CASE("Checking Movie Theater")
{
    GIVEN("a MovieTheater object")
    {
        auto movie = new Movie("The Dark Knight", "A movie about Batman");
        auto theater = new Theater(25, "Regal Cinemas", "New York");
        auto movieTheater = new MovieTheater(movie, theater);
        THEN("the movie and theater are as expected")
        {
            REQUIRE(movieTheater->getMovie()->getMovieName() == "The Dark Knight");
            REQUIRE(movieTheater->getTheater()->getTheaterName() == "Regal Cinemas");
        }
        THEN("the available seats are as expected")
        {
            auto availableSeats = movieTheater->getAvailableSeats();
            REQUIRE(availableSeats.size() == 25);
        }
        THEN("the seats can be booked")
        {
            vector<string> seats = {"a1", "a2", "a3"};
            REQUIRE(movieTheater->bookSeat(seats) == true);
            auto availableSeats = movieTheater->getAvailableSeats();
            REQUIRE(availableSeats.size() == 22);
        }
        THEN("the seats can be cancelled")
        {
            vector<string> seats = {"a1", "a2", "a3"};
            movieTheater->bookSeat(seats);
            movieTheater->cancelSeats(seats);
            auto availableSeats = movieTheater->getAvailableSeats();
            REQUIRE(availableSeats.size() == 25);
        }
    }
}

TEST_CASE("Checking DB")
{
    GIVEN("a DB object")
    {
        DB::getInstance().clearDB();
        auto movie = new Movie("The Dark Knight", "A movie about Batman");
        auto theater = new Theater(20, "Regal Cinemas", "New York");
        auto theater2 = new Theater(20, "AMC", "New York");
        auto movieTheater = new MovieTheater(movie, theater);
        auto movieTheater2 = new MovieTheater(movie, theater2);
        THEN("the movies, theaters and movie theaters can be added and retrieved")
        {
            DB::getInstance().addMovie(movie);
            DB::getInstance().addTheater(theater);
            DB::getInstance().addMovieTheater(movieTheater);
            DB::getInstance().addTheater(theater2);
            DB::getInstance().addMovieTheater(movieTheater2);
            auto movies = DB::getInstance().getMovies();
            auto theaters = DB::getInstance().getTheaters();
            auto movieTheaters = DB::getInstance().getMovieTheaters("The Dark Knight");
            auto movieTheater3 = DB::getInstance().getMovieTheater("The Dark Knight", "Regal Cinemas");
            REQUIRE(movies.size() == 1);
            REQUIRE(theaters.size() == 2);
            REQUIRE(movieTheaters.size() == 2);
            REQUIRE(movieTheater3->getMovie()->getMovieName() == "The Dark Knight");
            REQUIRE(movieTheater3->getTheater()->getTheaterName() == "Regal Cinemas");
        }
    }
}

TEST_CASE("Checking Views")
{
    GIVEN("a Views object")
    {
        auto movie = new Movie("The Dark Knight", "A movie about Batman");
        auto theater = new Theater(25, "Regal Cinemas", "New York");
        auto movieTheater = new MovieTheater(movie, theater);
        DB::getInstance().clearDB();
        DB::getInstance().addMovie(movie);
        DB::getInstance().addTheater(theater);
        DB::getInstance().addMovieTheater(movieTheater);
        THEN("the movies, theaters and available seats can be retrieved")
        {
            auto movies = Views::getInstance().getMovies();
            auto theaters = Views::getInstance().getTheaters("The Dark Knight");
            auto availableSeats = Views::getInstance().getAvailableSeats("The Dark Knight", "Regal Cinemas");
            REQUIRE(movies.size() == 1);
            REQUIRE(theaters.size() == 1);
            REQUIRE(availableSeats.size() == 25);
        }
        THEN("the seats can be booked")
        {
            vector<string> seats = {"a1", "a2", "a3"};
            auto booked = Views::getInstance().bookSeats(seats, "The Dark Knight", "Regal Cinemas");
            REQUIRE(booked["status"] == "success");
        }
    }
}

int main(int argc, char *argv[])
{
    Catch::Session session; // There must be exactly one instance

    int returnCode = session.applyCommandLine(argc, argv);
    if (returnCode != 0) // Indicates a command line error
        return returnCode;

    int numFailed = session.run();
    return numFailed;
}
