cmake_minimum_required(VERSION 3.15)
project(SAARM_Tactical_System VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -O3")

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(Qt5 COMPONENTS Core Network Gui Qml Quick REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIR})

add_subdirectory(flight_controller)
add_subdirectory(ground_c2_station)