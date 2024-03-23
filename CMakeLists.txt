cmake_minimum_required(VERSION 3.24)

project(tnp-generator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} src/main.cpp
    include/user.hpp
    src/user.cpp
    include/offer.hpp
)