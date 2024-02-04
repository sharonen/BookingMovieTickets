cmake_minimum_required(VERSION 3.6.0)
project(BookingMovieTickets_app)

set(CMAKE_CXX_STANDARD 14)


include_directories(${CONAN_INCLUDE_DIRS})



add_subdirectory(src)

enable_testing()
add_subdirectory(unit_tests)
add_test(NAME BookingMovieTicketsTests
         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
         COMMAND BookingMovieTicketsTests)