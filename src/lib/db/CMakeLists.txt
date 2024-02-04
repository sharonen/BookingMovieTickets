cmake_minimum_required(VERSION 3.6.0)
project(DB)
set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE PROJECT_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(DB STATIC ${PROJECT_SOURCE})
target_link_libraries(DB  ${CONAN_LIBS})