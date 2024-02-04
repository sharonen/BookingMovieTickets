cmake_minimum_required(VERSION 3.6.0)
project(BookingMovieTicketsLibs)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(db)
add_subdirectory(movie)
add_subdirectory(movie_theater)
add_subdirectory(theater)
add_subdirectory(views)