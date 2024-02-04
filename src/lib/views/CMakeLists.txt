cmake_minimum_required(VERSION 3.6.0)
project(Views)
set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE PROJECT_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

find_package(nlohmann_json 3.11.3 REQUIRED)

add_library(Views STATIC ${PROJECT_SOURCE})
target_link_libraries(Views  ${CONAN_LIBS})

target_link_libraries(Views nlohmann_json::nlohmann_json)

