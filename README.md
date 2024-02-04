# BookingMovieTickets

# Description: 

# This is a simple project to book movie tickets. The project is implemented using C++ and CMake. The project uses the following libraries:
1. Catch2: For unit testing
2. nlohmann/json: For json parsing

# The project has the following structure:
1. src: Contains the source code for the project
2. unit_test: Contains the unit tests for the project
3. CMakeLists.txt: The main CMake file for the project
4. conanfile.py: The conan file for the project

# The project has the following classes:
1. Movie: Represents a movie
2. Theater: Represents a theater
3. MovieTheater: Represents a relashionship between a movie and a theater
4. DB: Represents a database for the project
5. Views: Represents a class with API calls for the project

# The project has the following API calls:
1. GetMovies: Gets all the movies from the database
2. GetTheatersByMovie: Gets all the movie theaters for a specific movie from the database
8. GetAvailableSeats: Gets all the available seats for a specific movie and a specific theater from the database
9. BookSeats: Books seats for a specific movie and a specific theater from the database


# The project has the following unit tests:
1. TestMovie: Tests the Movie class
2. TestTheater: Tests the Theater class
3. TestMovieTheater: Tests the MovieTheater class
4. TestDB: Tests the DB class
5. TestViews: Tests the Views class

# Installation and Build using CMake and Conan

# Installation:
1. Clone the repository
2. Open the project 
3. pip install conan

# Build and Run:
1. conan install . --output-folder=build --build=missing
2. cd build
3. cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
4. cmake --build .  

# Running unit tests

1. cd BookingMovieTickets/build
2. ctest -V 


# Next Steps:

1. Add a support for running the project in a container
2. Add a support for running HTTP requests, using something like Crow https://crowcpp.org/master/
3. Add support to generate documentation using Doxygen
4. Add a support for running the project in a cloud environment, using something like AWS Lambda
