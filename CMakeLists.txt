cmake_minimum_required(VERSION 3.13)
project(starwars2)

set(CMAKE_CXX_STANDARD 17)

add_executable(starwars2 starwars2_example.cc src/battle.cc src/rebelfleet.cc src/imperialfleet.cc src/helper.cc)
add_executable(test0 test0.cpp src/rebelfleet.cc src/imperialfleet.cc src/helper.cc src/battle.cc)
add_executable(test1 test1.cc src/rebelfleet.cc src/imperialfleet.cc src/helper.cc src/battle.cc)
add_executable(test2 test1.cc src/rebelfleet.cc src/imperialfleet.cc src/helper.cc src/battle.cc)