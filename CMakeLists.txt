cmake_minimum_required(VERSION 3.3)
project(TronSnake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Game.h main.cpp Tail.h Tail.cpp Food.h Food.cpp Grid.h Grid.cpp Game.cpp Entity.h Entity.cpp)

add_executable(TronSnake ${SOURCE_FILES})