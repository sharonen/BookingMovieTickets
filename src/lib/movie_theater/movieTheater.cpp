#include "movieTheater.hpp"

// Constructor for MovieTheater
MovieTheater::MovieTheater(Movie *movie, Theater *theater)
{
    this->movie = movie;
    this->theater = theater;
    // Intialise the available seats as true
    for (char row = 'a'; row <= 'e'; row++)
    {
        for (int i = 1; i <= theater->getTheaterCapacity() / 5; i++)
        {
            string seatNumber = row + to_string(i);
            availableSeats[seatNumber] = true;
        }
    }
}

// Get the movie object
Movie *MovieTheater::getMovie()
{
    return movie;
}

// Get the theater object
Theater *MovieTheater::getTheater()
{
    return theater;
}
// Get the available seats
vector<string> MovieTheater::getAvailableSeats()
{
    vector<string> availableSeatsResult;
    for (auto seat : availableSeats)
    {
        if (seat.second)
        {
            availableSeatsResult.push_back(seat.first);
        }
    }
    return availableSeatsResult;
}
// Book a seat
bool MovieTheater::bookSeat(vector<string> seatNumbers)
{
    std::lock_guard<std::mutex> guard(mu_);
    for (auto seatNumber : seatNumbers)
    {
        if (!availableSeats[seatNumber])
        {
            // If the seat is not available, cancel the booking and return false
            this->cancelSeats(seatNumbers);
            return false;
        }
        availableSeats[seatNumber] = false;
    }
    return true;
}
// Cancel a seat
void MovieTheater::cancelSeats(vector<string> seatNumbers)
{
    std::lock_guard<std::mutex> guard(mu_);
    for (auto seatNumber : seatNumbers)
    {
        availableSeats[seatNumber] = true;
    }
}
// Check if the seats are available
bool MovieTheater::checkSeats(vector<string> seatNumbers)
{
    for (auto seatNumber : seatNumbers)
    {
        if (!availableSeats[seatNumber])
        {
            return false;
        }
    }
    return true;
}