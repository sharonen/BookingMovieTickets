# BookingMovieTickets



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
