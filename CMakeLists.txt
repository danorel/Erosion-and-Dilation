cmake_minimum_required(VERSION 3.9)
project(Erosion_Dilation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(
        Erosion_Dilation main.cpp
        erosion.cpp
        dilation.cpp
)

# linking
target_link_libraries(Erosion_Dilation ${OpenCV_LIBS})