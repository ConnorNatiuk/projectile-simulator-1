cmake_minimum_required(VERSION 3.28)
project(Simulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS Graphics)

add_executable(Simulator src/main.cpp)
target_link_libraries(Simulator PRIVATE SFML::Graphics)
