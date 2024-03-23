cmake_minimum_required(VERSION 3.24)

project(tnp-generator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} src/main.cpp
                            src/offer.cpp
                            src/util.cpp
                            src/user.cpp
                            src/include/user.hpp
                            src/include/notification.hpp
                            src/include/visit.hpp
                            src/include/util.hpp
                            src/include/searched_route.hpp
                            src/include/request.hpp
                            src/include/request.hpp
                            src/include/search_timestamp.hpp
                            src/include/problem.hpp
                            src/include/offer.hpp
                            src/include/state.hpp
                            src/include/review.hpp

)