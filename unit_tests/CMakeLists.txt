cmake_minimum_required(VERSION 3.6.0)
project(BookingMovieTicketsTests)

file(GLOB_RECURSE TEST_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

find_package(Catch2 REQUIRED)


add_executable(BookingMovieTicketsTests ${TEST_SOURCE})
target_link_libraries(BookingMovieTicketsTests DB ${CONAN_LIBS})
target_link_libraries(BookingMovieTicketsTests Movie ${CONAN_LIBS})
target_link_libraries(BookingMovieTicketsTests MovieTheater ${CONAN_LIBS})
target_link_libraries(BookingMovieTicketsTests Theater ${CONAN_LIBS})
target_link_libraries(BookingMovieTicketsTests Views ${CONAN_LIBS})

target_link_libraries(BookingMovieTicketsTests Catch2::Catch2WithMain)
