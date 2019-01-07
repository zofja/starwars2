cmake_minimum_required(VERSION 3.13)
project(starwars2)

set(CMAKE_CXX_STANDARD 17)

#add_executable(starwars2 starwars2_example.cc src/rebelfleet.cc src/imperialfleet.cc src/helper.cc)

add_executable(test test.cc src/rebelfleet.cc src/imperialfleet.cc src/helper.cc src/battle.cc)