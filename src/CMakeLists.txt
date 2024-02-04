cmake_minimum_required(VERSION 3.6.0)
project(BookingMovieTickets)

set(CMAKE_CXX_STANDARD 14)
file(GLOB_RECURSE PROJECT_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

find_package(nlohmann_json 3.11.3 REQUIRED)

set(PROJECT_MAIN "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
add_executable(BookingMovieTickets ${PROJECT_MAIN})




target_link_libraries(BookingMovieTickets DB ${CONAN_LIBS})
target_link_libraries(BookingMovieTickets Movie ${CONAN_LIBS})
target_link_libraries(BookingMovieTickets MovieTheater ${CONAN_LIBS})
target_link_libraries(BookingMovieTickets Theater ${CONAN_LIBS})
target_link_libraries(BookingMovieTickets Views ${CONAN_LIBS})

target_link_libraries(BookingMovieTickets nlohmann_json::nlohmann_json)


add_subdirectory(lib)